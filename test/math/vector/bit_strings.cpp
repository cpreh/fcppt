//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/vector/bit_strings.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <array>
#include <iostream>
#include <iterator>
#include <ostream>
#include <vector>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	math_vector_bit_strings
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::math::vector::static_<
		int,
		2
	>
	vector2;

	typedef
	fcppt::math::vector::static_<
		int,
		3
	>
	vector3;

	typedef
	std::array<
		vector2,
		4
	>
	vector2_container;

	typedef
	std::array<
		vector3,
		8
	>
	vector3_container;

	vector2_container const result2(
		fcppt::math::vector::bit_strings<
			int,
			2
		>()
	);

	std::cout << "Result: \n";

	for(
		auto const &element
		:
		result2
	)
		std::cout << element << '\n';

	std::cout << "Now checking...\n";

	BOOST_REQUIRE_EQUAL(
		result2.size(),
		4u
	);

	BOOST_CHECK_EQUAL(
		result2[0],
		vector2(0,0)
	);

	BOOST_CHECK_EQUAL(
		result2[1],
		vector2(1,0)
	);

	BOOST_CHECK_EQUAL(
		result2[2],
		vector2(0,1)
	);

	BOOST_CHECK_EQUAL(
		result2[3],
		vector2(1,1)
	);

	vector3_container const result3(
		fcppt::math::vector::bit_strings<
			int,
			3
		>()
	);

	std::cout << "Result: \n";

	for(
		auto const &element
		:
		result3
	)
		std::cout << element << '\n';

	BOOST_REQUIRE_EQUAL(
		result3.size(),
		8u
	);

	BOOST_CHECK_EQUAL(
		result3[0],
		vector3(0,0,0)
	);

	BOOST_CHECK_EQUAL(
		result3[1],
		vector3(1,0,0)
	);

	BOOST_CHECK_EQUAL(
		result3[2],
		vector3(0,1,0)
	);

	BOOST_CHECK_EQUAL(
		result3[3],
		vector3(1,1,0)
	);

	BOOST_CHECK_EQUAL(
		result3[4],
		vector3(0,0,1)
	);

	BOOST_CHECK_EQUAL(
		result3[5],
		vector3(1,0,1)
	);

	BOOST_CHECK_EQUAL(
		result3[6],
		vector3(0,1,1)
	);

	BOOST_CHECK_EQUAL(
		result3[7],
		vector3(1,1,1)
	);
}
