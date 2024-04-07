# Create a signal test.
function(add_fcppt_signal_test test_name)
  add_fcppt_test(signal/${test_name} ${ARGN})
endfunction()

add_fcppt_signal_test(move LINK_LIBS "${fcppt_core_TARGET}")

add_fcppt_signal_test(object LINK_LIBS "${fcppt_core_TARGET}")

add_fcppt_signal_test(unregister LINK_LIBS "${fcppt_core_TARGET}")
