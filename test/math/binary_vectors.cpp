//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/generate_binary_vectors.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/vector/static.hpp>
#include <boost/test/unit_test.hpp>
#include <boost/foreach.hpp>
#include <iostream>
#include <iterator>
#include <vector>

BOOST_AUTO_TEST_CASE(
	binary_vectors)
{
	typedef
	fcppt::math::vector::static_<int,2>::type
	vector2;

	typedef
	fcppt::math::vector::static_<int,3>::type
	vector3;

	typedef
	fcppt::container::array
	<
		vector2,
		4
	>
	vector2_container;

	typedef
	fcppt::container::array
	<
		vector3,
		8
	>
	vector3_container;

	std::cout << "Generating 2D binary vectors...\n";

	vector2_container result2 = 
		fcppt::math::generate_binary_vectors<int,2>();

	std::cout << "Result: \n";
	BOOST_FOREACH(
		vector2 const &v,
		result2)
		std::cout << v << "\n";

	std::cout << "Now checking...\n";

	BOOST_CHECK(
		result2[0] == vector2(0,0));
	BOOST_CHECK(
		result2[1] == vector2(1,0));
	BOOST_CHECK(
		result2[2] == vector2(0,1));
	BOOST_CHECK(
		result2[3] == vector2(1,1));

	std::cout << "Generating 3D binary vectors...\n";

	vector3_container result3 = 
		fcppt::math::generate_binary_vectors<int,3>();

	std::cout << "Result: \n";
	BOOST_FOREACH(
		vector3 const &v,
		result3)
		std::cout << v << "\n";

	std::cout << "Now checking...\n";

	BOOST_CHECK(
		result3.size() == static_cast<vector3_container::size_type>(8));
	BOOST_CHECK(
		result3[0] == vector3(0,0,0));
	BOOST_CHECK(
		result3[1] == vector3(1,0,0));
	BOOST_CHECK(
		result3[2] == vector3(0,1,0));
	BOOST_CHECK(
		result3[3] == vector3(1,1,0));
	BOOST_CHECK(
		result3[4] == vector3(0,0,1));
	BOOST_CHECK(
		result3[5] == vector3(1,0,1));
	BOOST_CHECK(
		result3[6] == vector3(0,1,1));
	BOOST_CHECK(
		result3[7] == vector3(1,1,1));
}
