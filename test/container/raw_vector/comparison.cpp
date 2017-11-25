//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/raw_vector/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	container_raw_vector_comparison
)
{
	typedef
	fcppt::container::raw_vector::object<
		int
	>
	container_type;

	container_type const test1{
		1,
		2
	};

	container_type const test2{
		2,
		3
	};

	container_type const test3{
		1,
		2
	};

	BOOST_CHECK(
		test1
		==
		test3
	);

	BOOST_CHECK(
		test1
		!=
		test2
	);

	BOOST_CHECK(
		test1
		<
		test2
	);

	BOOST_CHECK(
		test2
		>
		test1
	);
}
