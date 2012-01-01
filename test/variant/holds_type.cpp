//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/variant/holds_type.hpp>
#include <fcppt/variant/object.hpp>
#include <fcppt/variant/recursive.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <boost/test/unit_test.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	variant_holds_type
)
{
	typedef fcppt::variant::object<
		boost::mpl::vector2<
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
		fcppt::variant::holds_type<
			std::string
		>(
			test
		)
	);

	BOOST_REQUIRE(
		!fcppt::variant::holds_type<
			int
		>(
			test
		)
	);

	variant const test2(
		42
	);

	BOOST_REQUIRE(
		!fcppt::variant::holds_type<
			std::string
		>(
			test2
		)
	);

	BOOST_REQUIRE(
		fcppt::variant::holds_type<
			int
		>(
			test2
		)
	);
}

namespace
{

struct foo;

typedef fcppt::variant::object<
	boost::mpl::vector2<
		int,
		fcppt::variant::recursive<
			foo
		>
	>
> rec_variant;

struct foo
{
	explicit foo(
		rec_variant const &_variant
	)
	:
		variant_(
			_variant
		)
	{
	}

	rec_variant variant_;
};

}

BOOST_AUTO_TEST_CASE(
	variant_holds_type_recursive
)
{
	rec_variant const test((
		foo(
			rec_variant(
				42
			)
		)
	));

	BOOST_REQUIRE(
		fcppt::variant::holds_type<
			foo
		>(
			test
		)
	);
}
