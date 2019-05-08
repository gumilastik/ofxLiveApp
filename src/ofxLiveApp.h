#pragma once

#include "ofMain.h"

#if defined(TARGET_WIN32)
extern "C" void __blink_sync(const char *source_file);
extern "C" void __blink_release(const char *source_file, bool success);
#elif defined(TARGET_OSX)
#include <jet/live/Live.hpp>
#include <jet/live/Utility.hpp>
#include <jet/live/ILiveListener.hpp>

class JetListener : public jet::ILiveListener
{
public:
	JetListener(std::function<void()>&& codePreLoadCallback, std::function<void()>&& codePostLoadCallback);
	void onLog(jet::LogSeverity severity, const std::string& message) override;
	void onCodePreLoad() override;
	void onCodePostLoad() override;

private:
	std::function<void()> m_codePreLoadCallback;
	std::function<void()> m_codePostLoadCallback;
};
#endif

class ofxLiveApp : public ofBaseApp {
#if defined(TARGET_WIN32)
#elif defined(TARGET_OSX)
	bool filesRecompiled;
	std::unique_ptr<jet::Live> live;
	std::unique_ptr<jet::ILiveListener> listener;
#endif

public:
	ofxLiveApp();

	virtual void reinit();
	void __sync(ofEventArgs &args);
};
