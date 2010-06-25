//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/assign_multi_array.hpp>
#include <fcppt/homogenous_pair.hpp>
#include <boost/multi_array.hpp>
#include <boost/test/unit_test.hpp>
#include <cstddef>

BOOST_AUTO_TEST_CASE(assign_multi_array)
{
	typedef fcppt::homogenous_pair<
		std::size_t
	> unsigned_pair;

	typedef boost::multi_array<
		unsigned_pair,
		2
	> i2_array;

	typedef i2_array::size_type size_type;

	i2_array array1(
		boost::extents[3][5]
	);

	i2_array array2(
		boost::extents[4][6]
	);

	for(
		size_type y = 0; y < array2.shape()[1]; ++y
	)
		for(
			size_type x = 0; x < array2.shape()[0]; ++x
		)
			array2[x][y] = unsigned_pair(x, y);

	fcppt::container::assign_multi_array(
		array1,
		array2
	);

	for(
		size_type y = 0; y < array1.shape()[1]; ++y
	)
		for(
			size_type x = 0; x < array1.shape()[0]; ++x
		)
		{
			unsigned_pair const elem(
				array1[x][y]
			);

			BOOST_REQUIRE(
				elem.first == x
				&& elem.second == y
			);
		}
}
