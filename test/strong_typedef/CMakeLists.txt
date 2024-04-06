function(add_fcppt_strong_typedef_test TEST_NAME)
  add_fcppt_test(strong_typedef/${TEST_NAME} ${ARGN})
endfunction()

add_fcppt_strong_typedef_test(apply)

add_fcppt_strong_typedef_test(hash)

add_fcppt_strong_typedef_test(io)

add_fcppt_strong_typedef_test(make)

add_fcppt_strong_typedef_test(map LINK_LIBS ${fcppt_core_TARGET}
                              fcppt_catch_interface)

add_fcppt_strong_typedef_test(object)

add_fcppt_strong_typedef_test(operations)

add_fcppt_strong_typedef_test(tag NO_CODE)
