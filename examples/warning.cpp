//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[warning
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>

//<-

namespace
{
//->

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

// disable the warning that triggers
// if 'this' is used in the constructor
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

float
test()
{
FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Wold-style-cast)
	float const f(
		(float)(42)
	);

	return f;
FCPPT_PP_POP_WARNING
}
//]

}

int main()
{
	test();
}
