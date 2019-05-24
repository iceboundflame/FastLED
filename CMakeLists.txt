project(FastLED)
add_library(${PROJECT_NAME}
        FastLED.cpp
        bitswap.cpp
        colorpalettes.cpp
        colorutils.cpp
        hsv2rgb.cpp
        lib8tion.cpp
        noise.cpp
        power_mgt.cpp
        wiring.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})
