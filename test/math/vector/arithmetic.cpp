//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/vector/arithmetic.hpp>
#include <fcppt/math/vector/comparison.hpp>
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
	vector_arithmetic_self
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::math::vector::static_<
		unsigned,
		2
	>
	ui2_vector;

	typedef
	fcppt::math::vector::static_<
		int,
		2
	>
	i2_vector;

	ui2_vector vec(
		0u,
		0u
	);

	vec +=
		ui2_vector(
			1u,
			2u
		);

	BOOST_CHECK_EQUAL(
		vec,
		ui2_vector(
			1u,
			2u
		)
	);

	vec *= 2u;

	BOOST_CHECK_EQUAL(
		vec,
		ui2_vector(
			2u,
			4u
		)
	);

	i2_vector veci(
		1,
		2
	);

	veci = -veci;

	BOOST_CHECK_EQUAL(
		veci,
		i2_vector(
			-1,
			-2
		)
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	vector_arithmetic_free
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::math::vector::static_<
		int,
		2
	>
	i2_vector;

	BOOST_CHECK_EQUAL(
		i2_vector(
			1,
			2
		)
		+
		i2_vector(
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
		i2_vector(
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
		i2_vector(
			3,
			4
		),
		i2_vector(
			6,
			12
		)
	);

	BOOST_CHECK_EQUAL(
		-i2_vector(
			2,
			3
		),
		i2_vector(
			-2,
			-3
		)
	);

	BOOST_CHECK_EQUAL(
		2
		*
		i2_vector(
			2,
			3
		),
		i2_vector(
			4,
			6
		)
	);

	BOOST_CHECK_EQUAL(
		i2_vector(
			2,
			3
		)
		*
		2,
		i2_vector(
			4,
			6
		)
	);

	BOOST_CHECK_EQUAL(
		i2_vector(
			4,
			6
		)
		/
		2,
		fcppt::optional::make(
			i2_vector(
				2,
				3
			)
		)
	);

	BOOST_CHECK_EQUAL(
		i2_vector(
			6,
			6
		)
		/
		i2_vector(
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
			i2_vector(
				2,
				0
			)
		).has_value()
	);
}
