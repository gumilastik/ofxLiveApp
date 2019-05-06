# ofxLiveApp

Live coding for openFrameworks! Magic!

* For OSX used [jet-live](https://github.com/ddovod/jet-live)
* For Windows used [blink](https://github.com/crosire/blink)

## SETUP

1.	* **OSX**:
		- Install xcpretty: 
          ```
          gem install xcpretty  
          ```
		- Run in the project directory for the first time (and each time the project structure changes):
          ```
          xcodebuild -project PROJECT_NAME.xcodeproj | xcpretty -r json-compilation-database --output compile_commands.json
          ```
          Change PROJECT_NAME to the name of your project
	* **WIN**:
		- Add props file from addon to your project (via the "Property Manager" window in Visual Studio)
		- Use x64 build

2. Inherit your main app from `ofxLiveApp` (instead of `ofApp` class)
3. `ofxLiveApp` add new function `void reinit();` to your app. 
This function is called after changes are loaded, so you can reinit your objects (if necessary)
