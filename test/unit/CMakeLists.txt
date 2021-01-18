IF (WIN32)
    # Windows
    message("TODO add gtest support for windows")
    add_subdirectory(old_test)
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
