//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/variant/holds_type.hpp>
#include <fcppt/variant/object.hpp>
#include <fcppt/variant/recursive.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <boost/test/unit_test.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	variant_assign
)
{
FCPPT_PP_POP_WARNING

	typedef fcppt::variant::object<
		boost::mpl::vector2<
			int,
			std::string
		>
	> variant;

	variant test1(
		0
	);

	variant test2(
		std::string(
			"test"
		)
	);

	test1 = test2;

	BOOST_REQUIRE(
		fcppt::variant::holds_type<
			std::string
		>(
			test1
		)
	);

	BOOST_REQUIRE(
		test1.get<
			std::string
		>()
		== "test"
	);

	test1 = 42;

	BOOST_REQUIRE(
		fcppt::variant::holds_type<
			int
		>(
			test1
		)
	);

	BOOST_REQUIRE(
		test1.get<
			int
		>()
		== 42
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

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	variant_recursive_assign
)
{
FCPPT_PP_POP_WARNING

	rec_variant test1(
		10
	);

	test1 =
		foo(
			rec_variant(
				42
			)
		);

	BOOST_REQUIRE(
		fcppt::variant::holds_type<
			foo
		>(
			test1
		)
	);

	BOOST_REQUIRE(
		test1.get<
			foo
		>().variant_.get<
			int
		>()
		== 42
	);

	test1 =
		rec_variant(
			foo(
				rec_variant(
					50
				)
			)
		);

	BOOST_REQUIRE(
		test1.get<
			foo
		>().variant_.get<
			int
		>()
		== 50
	);

	test1 = 100;

	BOOST_REQUIRE(
		fcppt::variant::holds_type<
			int
		>(
			test1
		)
	);

	BOOST_REQUIRE(
		test1.get<
			int
		>()
		== 100
	);
}
