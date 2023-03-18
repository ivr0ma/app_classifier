cmake_minimum_required(VERSION 3.21)
project(w1)

set(CMAKE_CXX_STANDARD 14)

add_executable(w1
        main.cpp classifier.cpp classifier.h Classifier_tree_2.cpp Classifier_tree_2.h Classifier_tree_1.cpp Classifier_tree_1.h)

set(CMAKE_MODULE_PATH "")