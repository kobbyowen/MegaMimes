# tests/CMakeLists.txt
cmake_minimum_required(VERSION 3.16)
add_executable(megamimes_tests
  test_main.c
  test_magic.c
  test_ext.c
  test_text.c
)
if(TARGET megamimes)
  target_link_libraries(megamimes_tests PRIVATE megamimes)
  if(WIN32)
    add_custom_command(TARGET megamimes_tests POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:megamimes>
        $<TARGET_FILE_DIR:megamimes_tests>
    )
  endif()
else()
  target_link_libraries(megamimes_tests PRIVATE megamimes_static)
endif()
target_include_directories(megamimes_tests PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/../include
)
target_compile_features(megamimes_tests PRIVATE c_std_99)
add_test(NAME megamimes_tests COMMAND megamimes_tests)
