//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/dim/comparison.hpp>
#include <fcppt/math/dim/output.hpp>
#include <fcppt/math/dim/sequence.hpp>
#include <fcppt/math/dim/static.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object.hpp>
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
	dim_sequence
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::math::dim::static_<
		unsigned,
		2
	>
	ui2_dim;

	typedef
	fcppt::math::dim::static_<
		fcppt::optional::object<
			unsigned
		>,
		2
	>
	ui2_dim_opt;

	BOOST_CHECK_EQUAL(
		fcppt::math::dim::sequence(
			ui2_dim_opt{
				fcppt::optional::make(
					10u
				),
				fcppt::optional::make(
					20u
				)
			}
		),
		fcppt::optional::make(
			ui2_dim{
				10u,
				20u
			}
		)
	);

	BOOST_CHECK_EQUAL(
		fcppt::math::dim::sequence(
			ui2_dim_opt{
				fcppt::optional::object<
					unsigned
				>{},
				fcppt::optional::make(
					20u
				)
			}
		),
		fcppt::optional::object<
			ui2_dim
		>{}
	);

}
