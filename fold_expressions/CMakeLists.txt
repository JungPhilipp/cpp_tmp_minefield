set(LIB_HEADERS
  include/print_with_delimiter.h
  )
set(LIB_SRC
  )

set(HEADERS
  )
set(SRC
  main.cpp
  )


add_library(fold INTERFACE) #${LIB_SRC} ${LIB_HEADERS})
target_include_directories(fold INTERFACE include)


add_executable(fold_example ${SRC} ${HEADERS})
target_link_libraries(fold_example PRIVATE fold)


