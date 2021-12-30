# CMake generated Testfile for 
# Source directory: /home/bxiiiiii/progr
# Build directory: /home/bxiiiiii/progr/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test_run "../bin/Demo" "1" "1" "ww" "wwww" "6" "3" "9")
set_tests_properties(test_run PROPERTIES  PASS_REGULAR_EXPRESSION "name : ww
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
  请输入选择:" _BACKTRACE_TRIPLES "/home/bxiiiiii/progr/CMakeLists.txt;12;add_test;/home/bxiiiiii/progr/CMakeLists.txt;0;")
