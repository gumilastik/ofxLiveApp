vs:
	ADDON_DLLS_TO_COPY = bin/blink.exe
    ADDON_SOURCES_EXCLUDE += libs/efsw/%
    ADDON_SOURCES_EXCLUDE += libs/jet/%
    ADDON_SOURCES_EXCLUDE += libs/tiny-process-library/%
    ADDON_SOURCES_EXCLUDE += libs/utils/%
osx:
    ADDON_CFLAGS += -O0
    ADDON_CPPFLAGS += -O0 '-std=gnu++11'
    ADDON_LDFLAGS += -Wl,-export_dynamic -Wl,-flat_namespace -Wl,-search_paths_first -Wl,-headerpad_max_install_names -ldl
