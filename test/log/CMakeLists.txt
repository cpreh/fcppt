# Create a log test.
function(add_fcppt_log_test test_name)
  add_fcppt_test(
    log/${test_name}
    LINK_LIBS
    "${fcppt_core_TARGET}"
    "${fcppt_log_TARGET}"
    ${ARGN})
endfunction()

add_fcppt_log_test(location LINK_LIBS fcppt_catch_interface)
