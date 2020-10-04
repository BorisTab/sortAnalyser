cmake_minimum_required(VERSION 3.18)
project(sortAnalyser)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "-pthread")

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(sortAnalyser main.cpp Analyser/stats.h Analyser/stats.cpp UserInterface/gui.h UserInterface/gui.cpp consts.h UserInterface/Buttons/buttons.cpp UserInterface/Buttons/buttons.h UserInterface/UIExceptions/uiExceptions.cpp UserInterface/UIExceptions/uiExceptions.h)

target_link_libraries(sortAnalyser sfml-graphics sfml-audio)