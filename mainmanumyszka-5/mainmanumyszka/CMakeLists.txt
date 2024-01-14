cmake_minimum_required(VERSION 3.14)
project(mainmanumyszka)

#set(CMAKE_CXX_FLAGS_RELEASE “${CMAKE_CXX_FLAGS_RELEASE} /Zi”)
#set(CMAKE_SHARED_LINKER_FLAGS_RELEASE “${CMAKE_SHARED_LINKER_FLAGS_RELEASE} /DEBUG /OPT:REF /OPT:ICF”)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES MainMenu.cpp
        Piraci.cpp
        Zagadki.cpp
        fabula.cpp
        polskieZnaki.cpp
)

set(RESOURCE_FILES
        fonts/AngerStyles.ttf
        "fonts/Apache License.txt"
        fonts/Arial.ttf
        "fonts/CALIFORNIA PERSONAL USE.ttf"
        fonts/OpenSans-Bold.ttf
        fonts/OpenSans-BoldItalic.ttf
        fonts/OpenSans-ExtraBold.ttf
        fonts/OpenSans-ExtraBoldItalic.ttf
        fonts/OpenSans-Italic.ttf
        fonts/OpenSans-Light.ttf
        fonts/OpenSans-LightItalic.ttf
        fonts/OpenSans-Regular.ttf
        fonts/OpenSans-Semibold.ttf
        fonts/OpenSans-SemiboldItalic.ttf)

add_executable(mainmanumyszka-5 ${SOURCE_FILES} ${RESOURCE_FILES})
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(mainmanumyszka-5 sfml-system sfml-window sfml-graphics sfml-network)

set_target_properties(mainmanumyszka-5 PROPERTIES
        RESOURCE "${RESOURCE_FILES}")

file(COPY fonts DESTINATION ${PROJECT_BINARY_DIR})