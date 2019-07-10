set(LIB_HEADERS
  include/Vector.h
  )
set(LIB_SRC
  src/test.cpp
  )

set(HEADERS
  )
set(SRC
  main.cpp
  )

add_library(expression INTERFACE ) #${LIB_SRC} ${LIB_HEADERS})
target_include_directories(expression INTERFACE include)



add_executable(expression_example ${SRC} ${HEADERS})
target_link_libraries(expression_example PRIVATE expression fold)


