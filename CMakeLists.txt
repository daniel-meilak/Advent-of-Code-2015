cmake_minimum_required(VERSION 3.10)

project(AOC21 VERSION 1.0)

# compiler arguments
if (MSVC)
   add_compile_options(/Wall)
else()
   add_compile_options(-Wall -Werror -Wextra -pedantic)
endif()

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# specify build type
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# Test Results for each day
list(APPEND part_1 74 1598415 2572 254575 255 543903 46065 1342 207 492982 hepxxyzz 191164 664 2660 222870 213 1638 768 576 831600 111 1824 184 10723906903 2650453)
list(APPEND part_2 1795 3812909 2631 1038736 55 14687245 14134 2074 804 6989950 heqaabcc 87842 640 1256 117936 323 17 781 207 884520 188 1937 231 74850409 "") 

enable_testing()

# add executable and test each day
foreach(day RANGE 1 25)
   
   # leading zero for single digit days
   if (${day} LESS 10)
      set(day "0${day}")
   endif()

   # set week
   if(day LESS 8)
      set(week 1)
   elseif(day LESS 15)
      set(week 2)
   elseif(day LESS 22)
      set(week 3)
   else()
      set(week 4)
   endif()

   # add each executable
   add_executable(day_${day} ${PROJECT_SOURCE_DIR}/week_${week}/day_${day}/day_${day}.cpp)
   set_target_properties(day_${day} PROPERTIES OUTPUT_NAME "day_${day}.exe")

   # copy input over
   configure_file(${PROJECT_SOURCE_DIR}/week_${week}/day_${day}/input_${day} ${PROJECT_BINARY_DIR}/input_${day} COPYONLY)

   # set output for testing
   math(EXPR index ${day}-1)
   list(GET part_1 ${index} output_1)
   list(GET part_2 ${index} output_2)

   # test results
   add_test(NAME day_${day}_test COMMAND day_${day}.exe)
   set_tests_properties(day_${day}_test PROPERTIES PASS_REGULAR_EXPRESSION "${output_1}\n.*${output_2}" TIMEOUT 120)
   
endforeach()
