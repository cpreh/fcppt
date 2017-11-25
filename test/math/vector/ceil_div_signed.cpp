//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/vector/ceil_div_signed.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	math_vector_ceil_div_signed
)
{
	typedef
	fcppt::math::vector::static_<
		int,
		2
	>
	i2_vector;

	typedef
	fcppt::optional::object<
		i2_vector
	>
	result_type;

	result_type const result{
		fcppt::math::vector::ceil_div_signed(
			i2_vector{
				1,
				5
			},
			2
		)
	};

	BOOST_CHECK_EQUAL(
		result,
		result_type{
			i2_vector(
				1,
				3
			)
		}
	);
}
