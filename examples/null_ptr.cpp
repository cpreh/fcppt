//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/null_ptr.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <fcppt/config/external_end.hpp>


namespace
{

//! [null_ptr_funcs]
void
pointer_func(
	int *
);

void
int_func(
	int
);
//! [null_ptr_funcs]
void
pointer_func(
	int *
)
{
}

void
int_func(
	int
)
{
}

}

#include <fcppt/config/warnings.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Wconversion)
#if defined(FCPPT_CONFIG_HAVE_CONVERSION_NULL_WARNING)
FCPPT_PP_DISABLE_GCC_WARNING(-Wconversion-null)
#endif

int
main()
{
//! [null_ptr_call]
	// false is convertible to a pointer
	pointer_func(
		false
	);

	// NULL is convertible to an int
	int_func(
		NULL
	);

	// Make the intent clear
	pointer_func(
		fcppt::null_ptr()
	);

	// Does not compile
	/*
	int_func(
		fcppt::null_ptr()
	);
	*/
//! [null_ptr_call]
}

#include <fcppt/preprocessor/pop_warning.hpp>
FCPPT_PP_POP_WARNING
