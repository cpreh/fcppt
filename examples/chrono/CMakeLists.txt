MACRO (ADD_FCPPT_CHRONO_EXAMPLE name)
	ADD_EXECUTABLE (fcpptchrono${name} ${name}.cpp)
	TARGET_LINK_LIBRARIES (fcpptchrono${name} fcppt)
ENDMACRO ()

ADD_FCPPT_CHRONO_EXAMPLE(duration)
ADD_FCPPT_CHRONO_EXAMPLE(monotonic_clock)
ADD_FCPPT_CHRONO_EXAMPLE(system_clock)
ADD_FCPPT_CHRONO_EXAMPLE(time_point)
