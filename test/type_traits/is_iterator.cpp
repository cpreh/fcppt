//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/type_traits/is_iterator.hpp>
#include <boost/test/unit_test.hpp>
#include <string>

namespace
{

struct not_iterator
{};

}

BOOST_AUTO_TEST_CASE(
	type_traits_is_iterator
)
{
	BOOST_CHECK(
		fcppt::type_traits::is_iterator<
			int *
		>::value
	);

	BOOST_CHECK(
		fcppt::type_traits::is_iterator<
			int const *
		>::value
	);

	BOOST_CHECK(
		fcppt::type_traits::is_iterator<
			std::string::iterator
		>::value
	);

	BOOST_CHECK(
		fcppt::type_traits::is_iterator<
			std::string::const_iterator
		>::value
	);

	BOOST_CHECK(
		!fcppt::type_traits::is_iterator<
			int
		>::value
	);

	BOOST_CHECK(
		!fcppt::type_traits::is_iterator<
			not_iterator
		>::value
	);

}
