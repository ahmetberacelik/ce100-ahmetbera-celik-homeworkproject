if(EXISTS "/mnt/c/Users/Bera/Desktop/ce100-ahmetbera-celik-homeworkproject/build_linux/src/tests/utility/utility_tests[1]_tests.cmake")
  include("/mnt/c/Users/Bera/Desktop/ce100-ahmetbera-celik-homeworkproject/build_linux/src/tests/utility/utility_tests[1]_tests.cmake")
else()
  add_test(utility_tests_NOT_BUILT utility_tests_NOT_BUILT)
endif()