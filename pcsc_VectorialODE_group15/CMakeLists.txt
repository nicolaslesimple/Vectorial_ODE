cmake_minimum_required(VERSION 3.8)
project(pcsc_VectorialODE_group15)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Input.cpp
        Input.h
        Solution.cpp
        Solution.h
        Bashforth.cpp
        Bashforth.h
        BashforthFirstStep.cpp
        BashforthFirstStep.h
        VectorialODE.cpp
        VectorialODE.h
        RungeKutta.cpp
        RungeKutta.h
        BashforthSecondStep.cpp
        BashforthSecondStep.h
        BashforthThirdStep.cpp
        BashforthThirdStep.h
        BashforthFourthStep.cpp
        BashforthFourthStep.h
        RungeKutta.cpp
        RungeKutta.h
        RungeKuttaOrder2.cpp
        RungeKuttaOrder2.h
        RungeKuttaOrder4.cpp
        RungeKuttaOrder4.h)
add_executable(main main.cpp ${SOURCE_FILES})

################################################################
# Google test
################################################################


#Add the google test subdirectory
add_subdirectory(googletest)

#include googletest/include dir
include_directories(googletest/googletest/include)

#include the googlemock/include dir
include_directories(googletest/googlemock/include)

#Define your executable
add_executable(Test vector_test.cpp ${SOURCE_FILES})

#Link with GoogleTest
target_link_libraries(Test gtest gtest_main)

#Link with GoogleMock
target_link_libraries(Test gmock gmock_main)

