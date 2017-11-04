//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/div.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	math_div
)
{
FCPPT_PP_POP_WARNING

	BOOST_CHECK(
		!fcppt::math::div(
			2,
			0
		).has_value()
	);

	BOOST_CHECK_EQUAL(
		fcppt::math::div(
			6,
			2
		),
		fcppt::optional::make(
			3
		)
	);

	BOOST_CHECK(
		!fcppt::math::div(
			2.f,
			0.f
		).has_value()
	);
}