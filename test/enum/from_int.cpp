//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/exception.hpp>
#include <fcppt/catch/defer.hpp>
#include <fcppt/enum/from_int.hpp>
#include <fcppt/enum/from_int_exn.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <fcppt/config/external_end.hpp>


namespace
{

enum class test_enum
{
	enum1,
	enum2,
	fcppt_maximum = enum2
};

}

TEST_CASE(
	"enum::from_int",
	"[enum]"
)
{
	CHECK(
		fcppt::catch_::defer(
			fcppt::enum_::from_int<
				test_enum
			>(
				1u
			)
			==
			fcppt::optional::make(
				test_enum::enum2
			)
		)
	);

	CHECK_FALSE(
		fcppt::enum_::from_int<
			test_enum
		>(
			2u
		).has_value()
	);
}

TEST_CASE(
	"enum::from_int_exn",
	"[enum]"
)
{
	CHECK(
		fcppt::enum_::from_int_exn<
			test_enum
		>(
			1u
		)
		==
		test_enum::enum2
	);

	CHECK_THROWS_AS(
		fcppt::enum_::from_int_exn<
			test_enum
		>(
			2u
		),
		fcppt::exception
	);
}
