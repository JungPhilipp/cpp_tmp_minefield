set(SRC
    main_tests.cpp
    util/print.t.cpp
    )

add_executable(unit-tests ${SRC})
target_link_libraries(unit-tests PRIVATE Catch2::Catch2)
target_link_libraries(unit-tests PRIVATE util)

add_test(unit-tests unit-tests)

enable_testing()
