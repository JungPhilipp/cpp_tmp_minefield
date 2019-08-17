set (HEADERS
    util.h
    include/print.h)


add_library(util INTERFACE)
target_include_directories(util INTERFACE include)
