cmake_minimum_required(VERSION 3.11)

project(3rdparty)

add_subdirectory(aubio)
add_subdirectory(kiss_fft130)
add_subdirectory(laserdocklib)
add_subdirectory(lib-qt-qml-tricks)
add_subdirectory(libaudiodecoder)
add_subdirectory(nanosvg-master)
add_subdirectory(openlase)
add_subdirectory(simplecrypt)

if(LD_CORE_ENABLE_LIBLZR)
    add_subdirectory(liblzr)
endif()

if(LD_CORE_RESOURCES_EXTRACTOR)
    add_subdirectory(quazip)
endif()
