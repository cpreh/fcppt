MACRO (ADD_FCPPT_MATH_VECTOR_EXAMPLE name)
	ADD_EXECUTABLE (fcpptmathvector${name} ${name}.cpp)
	TARGET_LINK_LIBRARIES (fcpptmathvector${name} fcppt)
ENDMACRO ()

ADD_FCPPT_MATH_VECTOR_EXAMPLE(basic)
