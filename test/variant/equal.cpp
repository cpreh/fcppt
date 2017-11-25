//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/variant/comparison.hpp>
#include <fcppt/variant/object.hpp>
#include <fcppt/variant/type_info.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	variant_equal
)
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

	variant const v1(
		string
	);

	variant const v2(
		string
	);

	BOOST_CHECK(
		v1 == v2
	);

	variant const v3(
		42
	);

	BOOST_CHECK(
		v1 != v3
	);

	BOOST_CHECK(
		fcppt::variant::type_info(
			v1
		)
		==
		fcppt::variant::type_info(
			v2
		)
	);
}
