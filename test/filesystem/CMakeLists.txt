function(add_fcppt_filesystem_test TEST_NAME)
  add_fcppt_test(filesystem/${TEST_NAME} ${ARGN})
endfunction()

add_fcppt_filesystem_test(remove_extension LINK_LIBS fcppt_catch_interface
                          "${fcppt_filesystem_TARGET}")
