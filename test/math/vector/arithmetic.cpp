//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/vector/arithmetic.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	vector_arithmetic
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

	vec /= 2u;

	BOOST_CHECK_EQUAL(
		vec,
		ui2_vector(
			1u,
			2u
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

	veci = +veci;

	BOOST_CHECK_EQUAL(
		veci,
		i2_vector(
			-1,
			-2
		)
	);
}
