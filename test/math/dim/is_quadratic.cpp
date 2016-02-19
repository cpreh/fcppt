//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/dim/is_quadratic.hpp>
#include <fcppt/math/dim/static.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	dim_is_quadratic
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::math::dim::static_<
		unsigned,
		2
	>
	ui2_dim;

	BOOST_CHECK(
		!fcppt::math::dim::is_quadratic(
			ui2_dim{
				10u,
				20u
			}
		)
	);

	BOOST_CHECK(
		fcppt::math::dim::is_quadratic(
			ui2_dim{
				10u,
				10u
			}
		)
	);
}
