set(HEADERS
  include/print_with_delimiter.h
  )
set(SRC
  main.cpp
  )

add_executable(fold ${SRC} ${HEADERS})
target_include_directories(fold PUBLIC include)

