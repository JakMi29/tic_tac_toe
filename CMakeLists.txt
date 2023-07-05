cmake_minimum_required(VERSION 3.24)
project(untitled4)

set(CMAKE_CXX_STANDARD 17)
add_executable(untitled4 src/main.cpp headers/game.h src/game.cpp headers/field.h src/field.cpp headers/MinMax.h headers/Move.h headers/button.h src/button.cpp)
include_directories(headers usr/include c:/SFML/include)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package (SFML REQUIRED system window graphics)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(untitled4 ${SFML_LIBRARIES})
endif()

if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY
${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()
