cmake_minimum_required(VERSION 2.8)

project(Demo)

add_executable(../bin/Demo ../src/main.c ../src/UI.c ../src/Operations.c)

#aux_source_directory(src DIR_SRCS)
#set(Test ${DIR_SRCS})
#add_executable(${Test})

enable_testing()
add_test(test_run ../bin/Demo 1 1 ww wwww 6 3 9)

set_tests_properties (test_run
  PROPERTIES PASS_REGULAR_EXPRESSION "name : ww
  info : wwww
  coordinate : x-6 y-3
  [1]insert node
  [2]modify node
  [3]delete node
  [4]insert path
  [5]modify path
  [6]delete path
  [7]save change
  [8]exit
  //[9]show node
  //[10]show path
  请输入选择:")