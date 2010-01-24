MACRO (ADD_FCPPT_LOG_EXAMPLE name)
	ADD_EXECUTABLE (fcpptlog${name} ${name}.cpp)
	TARGET_LINK_LIBRARIES (fcpptlog${name} fcppt)
ENDMACRO ()

ADD_FCPPT_LOG_EXAMPLE(helloworld)
