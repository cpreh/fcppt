# Create a log example.
function(add_fcppt_log_example example_name)
  add_fcppt_example(log/${example_name} LINK_LIBS ${fcppt_core_TARGET}
                    ${fcppt_log_TARGET})
endfunction()

add_fcppt_log_example(context)

add_fcppt_log_example(formatting)

add_fcppt_log_example(helloworld)
