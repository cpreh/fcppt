//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/vector/object.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/math/vector/unit.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	math_vector_unit
)
{
FCPPT_PP_POP_WARNING

	typedef fcppt::math::vector::static_<
		int,
		3
	> int3_vector;

	int3_vector const vec(
		fcppt::math::vector::unit<
			int3_vector
		>(
			2
		)
	);

	BOOST_REQUIRE(
		vec[0] == 0
		&&
		vec[1] == 0
		&&
		vec[2] == 1
	);
}
