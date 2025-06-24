add_library(iniparser STATIC
    src/src/dictionary.c
    src/src/iniparser.c
)
target_include_directories(iniparser PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)