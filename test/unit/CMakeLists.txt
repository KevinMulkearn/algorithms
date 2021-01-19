IF (WIN32)
    # Windows
    # TODO: Fix - Unit test will not work unless .dll are copied into unit test folder with exectable. 
    find_package(GTest REQUIRED)
    find_package(Threads REQUIRED)

    add_library(unit_test_main unit_test_main.cpp)

    target_link_libraries(unit_test_main
        PUBLIC
        GTest::GTest)

    add_custom_target(unit-tests)

    add_subdirectory(sorting)
ELSE()
    # Linux
    find_package(GTest REQUIRED)

    add_library(unit_test_main unit_test_main.cpp)

    target_link_libraries(unit_test_main
        PUBLIC
        GTest::GTest)

    add_custom_target(unit-tests)

    add_subdirectory(sorting)
ENDIF()
