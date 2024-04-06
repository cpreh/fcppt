function(add_fcppt_signal_test TEST_NAME)
  add_fcppt_test(signal/${TEST_NAME} ${ARGN})
endfunction()

add_fcppt_signal_test(move LINK_LIBS "${fcppt_core_TARGET}")

add_fcppt_signal_test(object LINK_LIBS "${fcppt_core_TARGET}")

add_fcppt_signal_test(unregister LINK_LIBS "${fcppt_core_TARGET}")
