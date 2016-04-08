#set(LLVM_LINK_COMPONENTS
#  Core
#  ExecutionEngine
#  MC
#  MCJIT
#  Support
#  native
#  )

include_directories("/nix/store/dilhxsy4nkswdq8r1dbbxwmy7k1rn75g-boost-1.54.0-dev/include")
link_directories("/nix/store/zj7wwm2fr632v7myx1wdf9kvw75g68r7-boost-1.54.0-lib/lib")

#add_library(common STATIC

#)

add_clang_executable(lexer-benchmark
  test_utils.h
  test_utils.cpp
  main.cpp
  )

add_dependencies(lexer-benchmark
  clang-headers
  )

target_link_libraries(lexer-benchmark
  clangBasic
  clangLex
#  common
  boost_unit_test_framework
  boost_filesystem
  boost_system
  )

add_definitions("-std=c++11" "-Wno-parentheses" "-fpermissive")

#target_link_libraries(lexer-benchmark )
