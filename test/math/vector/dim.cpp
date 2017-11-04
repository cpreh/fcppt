//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/dim/static.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/dim.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/math/vector/static.hpp>
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
	vector_dim
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::math::vector::static_<
		int,
		2
	>
	i2_vector;

	typedef
	fcppt::math::dim::static_<
		int,
		2
	>
	i2_dim;

	BOOST_CHECK_EQUAL(
		i2_vector(
			1,
			2
		)
		+
		i2_dim(
			3,
			4
		),
		i2_vector(
			4,
			6
		)
	);

	BOOST_CHECK_EQUAL(
		i2_vector(
			5,
			2
		)
		-
		i2_dim(
			3,
			4
		),
		i2_vector(
			2,
			-2
		)
	);

	BOOST_CHECK_EQUAL(
		i2_vector(
			2,
			3
		)
		*
		i2_dim(
			3,
			4
		),
		i2_vector(
			6,
			12
		)
	);

	BOOST_CHECK_EQUAL(
		i2_vector(
			6,
			6
		)
		/
		i2_dim(
			2,
			3
		),
		fcppt::optional::make(
			i2_vector(
				3,
				2
			)
		)
	);

	BOOST_CHECK(
		!(
			i2_vector(
				6,
				6
			)
			/
			i2_dim(
				2,
				0
			)
		).has_value()
	);
}
