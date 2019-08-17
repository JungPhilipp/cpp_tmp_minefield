set(SRC
    Node.cpp)

set(HEADERS
    include/Node.h)

add_library(single_linked_list ${SRC} ${HEADERS})
target_include_directories(single_linked_list PUBLIC include)

target_link_libraries(single_linked_list PUBLIC util)