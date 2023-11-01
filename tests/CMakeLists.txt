set(${PROJECT_NAME}_tests)

file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/tests/src/*.cpp)

foreach(TEST_SRC_FILE ${TEST_SRC_FILES})
  get_filename_component(TEST_NAME ${TEST_SRC_FILE} NAME_WE)
  add_executable(${TEST_NAME} ${TEST_SRC_FILE})
  target_link_libraries(${TEST_NAME} gtest gmock gtest_main ${PROJECT_NAME}_lib)
  add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach()
