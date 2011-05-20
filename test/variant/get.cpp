//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/variant/object.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <boost/test/unit_test.hpp>
#include <string>

BOOST_AUTO_TEST_CASE(variant_get)
{
	typedef fcppt::variant::object<
		boost::mpl::vector3<
			bool,
			int,
			std::string
		>
	> variant;

	std::string const string(
		"hello world"
	);

	variant test(
		string
	);

	BOOST_REQUIRE(
		test.get<
			std::string
		>()
		==
		string
	);
}
