//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/cyclic_iterator.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <array>
#include <iterator>
#include <vector>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	cyclic_iterator_array
)
{
FCPPT_PP_POP_WARNING

	typedef std::array<
		int,
		3
	> int3_array;


	int3_array const array =
	{{
		1,
		2,
		3
	}};

	typedef fcppt::cyclic_iterator<
		int3_array::const_iterator
	> iterator;

	iterator test(
		array.begin(),
		array.begin(),
		array.end()
	);

	BOOST_REQUIRE(
		*test == 1
	);

	++test;

	BOOST_REQUIRE(
		*test == 2
	);

	++test;

	BOOST_REQUIRE(
		*test == 3
	);

	++test;

	BOOST_REQUIRE(
		*test == 1
	);

	BOOST_REQUIRE(
		test.get()
		== array.begin()
	);

	--test;

	BOOST_REQUIRE(
		*test == 3
	);

	BOOST_REQUIRE(
		test.get()
		== std::prev(
			array.end()
		)
	);

	--test;

	BOOST_REQUIRE(
		*test == 2
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	cyclic_iterator_empty
)
{
FCPPT_PP_POP_WARNING

	typedef std::vector<
		int
	> int_vector;

	int_vector vector;

	typedef fcppt::cyclic_iterator<
		int_vector::iterator
	> iterator;

	iterator test(
		vector.begin(),
		vector.begin(),
		vector.end()
	);

	++test;

	BOOST_REQUIRE(
		test.get()
		== vector.end()
	);
}
