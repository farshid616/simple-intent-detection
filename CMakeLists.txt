cmake_minimum_required(VERSION 3.10)
project(Simple_Intent_Detection)

set(CMAKE_CXX_STANDARD 11)


add_executable(Simple_Intent_Detection main.cpp RulesManager.cpp RulesManager.h SentenceParser.cpp SentenceParser.h)
