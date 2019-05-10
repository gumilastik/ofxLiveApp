meta:
    ADDON_NAME = ofxLiveApp
    ADDON_DESCRIPTION = Addon for live coding
    ADDON_AUTHOR = gumilastik
    ADDON_TAGS = "live coding"
    ADDON_URL = https://github.com/gumilastik/ofxLiveApp

common:
    ADDON_SOURCES_EXCLUDE += libs/efsw/%
    ADDON_SOURCES_EXCLUDE += libs/jet/%
    ADDON_SOURCES_EXCLUDE += libs/tiny-process-library/%
    ADDON_SOURCES_EXCLUDE += libs/utils/%

vs:
    ADDON_DLLS_TO_COPY += bin/blink.exe
    ADDON_DLLS_TO_COPY += bin/blink_x86.exe

osx:
    ADDON_CFLAGS += -O0
    ADDON_CPPFLAGS += -O0
    ADDON_LDFLAGS += -Wl,-export_dynamic -Wl,-flat_namespace -Wl,-search_paths_first -Wl,-headerpad_max_install_names -ldl
    ADDON_SOURCES_INCLUDE += libs/efsw/%
    ADDON_SOURCES_INCLUDE += libs/jet/%
    ADDON_SOURCES_INCLUDE += libs/tiny-process-library/%
    ADDON_SOURCES_INCLUDE += libs/utils/%
