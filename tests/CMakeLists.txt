set(SRC
    main_tests.cpp
    util/print.t.cpp
    data_structures/single_linked_list.t.cpp
    )

add_executable(unit-tests ${SRC})
target_link_libraries(unit-tests PRIVATE Catch2::Catch2)
target_link_libraries(unit-tests PRIVATE util single_linked_list)

add_test(unit-tests unit-tests)

enable_testing()
