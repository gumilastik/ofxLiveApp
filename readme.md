
# ofxLiveApp

Live coding for openFrameworks! Magic!

* For OSX used [jet-live](https://github.com/ddovod/jet-live)
* For Windows used [blink](https://github.com/crosire/blink)

## SETUP

1.	* OSX:
		- run in project dir: 
          ```
          gem install xcpretty  
          xcodebuild -project PROJECT_NAME.xcodeproj | xcpretty -r json-compilation-database --output compile_commands.json
          ```
	* WIN:
		- add props file from addon to your project
		- use x64 build

2. Inherit your main app from `ofxLiveApp` instead of `ofApp` class
3. `ofxLiveApp` add new virtual function `void reinit();` to your app. 
This function is called after changes are loaded, so you can reinit your objects (if necessary)
