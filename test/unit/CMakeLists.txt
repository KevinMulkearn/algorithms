find_package(GTest REQUIRED)

add_library(unit_test_main unit_test_main.cpp)

target_link_libraries(unit_test_main
    PUBLIC
    GTest::GTest)

add_custom_target(unit-tests)

add_subdirectory(searching)
add_subdirectory(sorting)
