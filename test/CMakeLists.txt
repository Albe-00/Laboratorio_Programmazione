cmake_minimum_required(VERSION 3.25)

add_subdirectory(googletest-main)
set(gtest_SOURCE_DIR, googletest-main/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTests.cpp OggettoTest.cpp ListaSpesaTest.cpp UtenteTest.cpp runAllTests.cpp)
add_executable(runTests ${TEST_SOURCE_FILES})

target_link_libraries(runTests gtest gtest_main core)