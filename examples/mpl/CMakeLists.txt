MACRO (ADD_FCPPT_MPL_EXAMPLE name)
	ADD_EXECUTABLE (fcpptmpl${name} ${name}.cpp)
	TARGET_LINK_LIBRARIES (fcpptmpl${name} fcppt)
ENDMACRO ()

ADD_FCPPT_MPL_EXAMPLE(for_each)
