# Create an options example.
function(add_fcppt_options_example example_name)
  add_fcppt_example(
    options/${example_name} COMPILE_OPTIONS ${FCPPT_UTILS_MAIN_COMPILE_OPTIONS}
    LINK_LIBS ${FCPPT_UTILS_MAIN_LINK_LIBS} ${ARGN})
endfunction()

add_fcppt_options_example(args LINK_LIBS ${fcppt_core_TARGET}
                          ${fcppt_options_TARGET})

add_fcppt_options_example(base LINK_LIBS ${fcppt_core_TARGET}
                         ${fcppt_options_TARGET})

add_fcppt_options_example(commands LINK_LIBS ${fcppt_core_TARGET}
                          ${fcppt_options_TARGET})

add_fcppt_options_example(
  complex LINK_LIBS ${fcppt_core_TARGET} ${fcppt_filesystem_TARGET}
  ${fcppt_log_TARGET} ${fcppt_options_TARGET})

add_fcppt_options_example(help LINK_LIBS ${fcppt_core_TARGET}
                          ${fcppt_options_TARGET})

add_fcppt_options_example(simple LINK_LIBS ${fcppt_core_TARGET}
                          ${fcppt_options_TARGET})
