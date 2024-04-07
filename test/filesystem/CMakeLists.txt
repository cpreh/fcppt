# Create a filesystem test.
function(add_fcppt_filesystem_test test_name)
  add_fcppt_test(filesystem/${test_name} ${ARGN})
endfunction()

add_fcppt_filesystem_test(remove_extension LINK_LIBS fcppt_catch_interface
                          "${fcppt_filesystem_TARGET}")
