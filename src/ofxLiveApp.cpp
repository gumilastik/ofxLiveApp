#include "ofxLiveApp.h"

#if defined(TARGET_WIN32)
std::mutex blink_mutex;
std::condition_variable blink_cv;
bool blink_wants_to_work = false;

void __blink_sync(const char * source_file)
{
	std::unique_lock<std::mutex> lock(blink_mutex);
	blink_wants_to_work = true;
	blink_cv.wait(lock); // Wait for app to allow us to continue
}

void __blink_release(const char * source_file, bool success)
{
	blink_wants_to_work = false;
	blink_cv.notify_one(); // Signal app thread that it may continue
}
#elif defined(TARGET_OSX)
JetListener::JetListener(std::function<void()>&& codePreLoadCallback, std::function<void()>&& codePostLoadCallback)
	: m_codePreLoadCallback(std::move(codePreLoadCallback))
	, m_codePostLoadCallback(std::move(codePostLoadCallback))
{
}

void JetListener::onLog(jet::LogSeverity severity, const std::string& message)
{
	std::string severityString;
	switch (severity) {
	case jet::LogSeverity::kInfo: severityString.append("[I]"); break;
	case jet::LogSeverity::kWarning: severityString.append("[W]"); break;
	case jet::LogSeverity::kError: severityString.append("[E]"); break;
	default: return;  // Skipping debug messages, they are too verbose
	}
	std::cout << severityString << " : " << message << std::endl;
}

void JetListener::onCodePreLoad()
{
	m_codePreLoadCallback();
}

void JetListener::onCodePostLoad()
{
	m_codePostLoadCallback();
}
#endif

ofxLiveApp::ofxLiveApp()
{
#if defined(TARGET_WIN32)
	STARTUPINFOA si = { 0 };
	PROCESS_INFORMATION pi = { 0 };

#if defined(_WIN64)
	string blink = "blink.exe";
#else
	string blink = "blink_x86.exe";
#endif
	string cmd = blink + " " + ofToString(GetCurrentProcessId());

	BOOL res = CreateProcessA(blink.c_str(), (char*)cmd.c_str(), NULL, NULL, NULL, 0, NULL, NULL, &si, &pi);

#elif defined(TARGET_OSX)
	filesRecompiled = false;

	jet::LiveConfig config;
	config.workerThreadsCount = 2;

	listener = jet::make_unique<JetListener>([&]() {}, [&]() { reinit(); });
	live = jet::make_unique<jet::Live>(std::move(listener), config);

	while (!live->isInitialized()) {
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		live->update();
	}

	live->update();
#endif

	ofAddListener(ofEvents().update, this, &ofxLiveApp::__sync);
}

void ofxLiveApp::reinit()
{

}

void ofxLiveApp::__sync(ofEventArgs &args)
{
#if defined (TARGET_WIN32)
	std::unique_lock<std::mutex> lock(blink_mutex);
	if (blink_wants_to_work)
	{
		blink_cv.notify_one(); // Notify "__blink_sync" to continue
		blink_cv.wait(lock); // Wait for "__blink_release" to allow continuation

		reinit();
	}
#elif defined(TARGET_OSX)
	live->update();
	if (live->getStatus().compilingFiles.size() == 0) {
		if (filesRecompiled) {
			live->tryReload();
			filesRecompiled = false;
		}
	}
	else {
		filesRecompiled = true;
	}
#endif
}
