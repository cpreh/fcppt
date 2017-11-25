//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/dynamic_array.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <iterator>
#include <fcppt/config/external_end.hpp>


template
class
fcppt::container::dynamic_array<
	int
>;


BOOST_AUTO_TEST_CASE(
	container_dynamic_array
)
{
	typedef
	fcppt::container::dynamic_array<
		int
	>
	int_array;

	int_array array1{
		10
	};

	BOOST_CHECK_EQUAL(
		std::distance(
			array1.data(),
			array1.data_end()
		),
		10
	);

	BOOST_CHECK_EQUAL(
		array1.size(),
		10u
	);

	int_array array2{
		0
	};

	BOOST_CHECK_EQUAL(
		array2.size(),
		0u
	);
}
