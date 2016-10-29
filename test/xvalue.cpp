//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_xvalue.hpp>
#include <fcppt/xvalue.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	xvalue
)
{
FCPPT_PP_POP_WARNING

	int x{
		42
	};

	fcppt::xvalue<
		int
	> val(
		x
	);

	BOOST_CHECK_EQUAL(
		&val.get(),
		&x
	);

	BOOST_CHECK_EQUAL(
		val.get(),
		42
	);

	BOOST_CHECK_EQUAL(
		&fcppt::make_xvalue(
			x
		).get(),
		&x
	);
}
