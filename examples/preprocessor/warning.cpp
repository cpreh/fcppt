//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>


namespace
{

//! [pp_warning_vc]
struct outer;

struct inner
{
	explicit inner(
		outer *
	)
	{
	}
};

struct outer
{

// Disable the warning that triggers when 'this' is used in the initialization
// list.
FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4355)
	outer()
	:
		inner_(
			this
		)
	{
	}
FCPPT_PP_POP_WARNING

	inner inner_;
};
//! [pp_warning_vc]

//! [pp_warning_gcc]
float
test()
{
// Here is a C macro from another library that uses a C style cast.
#define SOME_C_LIB_MACRO \
	(float)(42)

// Disable old style cast warning
FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Wold-style-cast)

	return SOME_C_LIB_MACRO;
FCPPT_PP_POP_WARNING
}
//! [pp_warning_gcc]

}

int
main()
{
	test();

	outer foo;

	inner bar(
		&foo
	);
}
