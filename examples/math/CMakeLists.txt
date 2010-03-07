MACRO (ADD_FCPPT_MATH_EXAMPLE name)
	ADD_EXECUTABLE (fcpptmath${name} ${name}.cpp)
	TARGET_LINK_LIBRARIES (fcpptmath${name} fcppt)
ENDMACRO ()

ADD_SUBDIRECTORY(vector)

ADD_FCPPT_MATH_EXAMPLE(matrix)
