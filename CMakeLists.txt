cmake_minimum_required(VERSION 3.23)
project(acceleratedCplus)

set(CMAKE_CXX_STANDARD 14)

add_executable(acceleratedCplus main.cpp)

add_executable(study1_frameGreeting2 study1/frameGreeting2.cpp study1/ex2_4_greeting.cpp study1/ex2_1.cpp study1/ex2_2.cpp study1/score.cpp study1/score2.cpp study1/ex3_3.cpp study1/ex3_4.cpp)
add_executable(study1_greeting study1/greeting.cpp)
add_executable(study1_greeting2 study1/greeting2.cpp)
add_executable(study1_greeting3 study1/greeting3.cpp)
add_executable(study1_ex2_4_greeting study1/ex2_4_greeting.cpp)
add_executable(study1_ex2_1 study1/ex2_1.cpp)
add_executable(study1_ex2_2 study1/ex2_2.cpp)
add_executable(study1_score study1/score.cpp)
add_executable(study1_score2 study1/score2.cpp)
add_executable(study1_ex3_3 study1/ex3_3.cpp)
add_executable(study1_ex3_4 study1/ex3_4.cpp)