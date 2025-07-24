add_library(DeviceManagerLib STATIC)

target_sources(DeviceManagerLib
    PRIVATE
        include/Device.h
		include/DeviceType.h
        src/Device.cpp
        src/Globals.h
        src/Globals.cpp
)

source_group("Header Files" REGULAR_EXPRESSION .+\\.h)
source_group("Source Files" REGULAR_EXPRESSION .+\\.cpp)

target_compile_definitions(DeviceManagerLib PRIVATE UNICODE _UNICODE)

target_include_directories(DeviceManagerLib
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
