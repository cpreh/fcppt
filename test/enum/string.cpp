//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/text.hpp>
#include <fcppt/enum/from_string.hpp>
#include <fcppt/enum/names_array.hpp>
#include <fcppt/enum/names_impl_fwd.hpp>
#include <fcppt/enum/to_string.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/test/defer.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <fcppt/config/external_end.hpp>


namespace
{

enum class test_enum
{
	test1,
	test2,
	test3,
	fcppt_maximum = test3
};

fcppt::enum_::names_array<
	test_enum
> const names{{{
	FCPPT_TEXT("test1"),
	FCPPT_TEXT("test2"),
	FCPPT_TEXT("test3")
}}};

}

namespace fcppt
{
namespace enum_
{

template<>
struct names_impl<
	test_enum
>
{
	static
	fcppt::enum_::names_array<
		test_enum
	> const &
	get()
	{
		return
			::names;
	}
};

}
}

TEST_CASE(
	"enum::to_string",
	"[enum]"
)
{
	CHECK(
		fcppt::enum_::to_string(
			test_enum::test1
		)
		==
		FCPPT_TEXT("test1")
	);

	CHECK(
		fcppt::enum_::to_string(
			test_enum::test2
		)
		==
		FCPPT_TEXT("test2")
	);
}

TEST_CASE(
	"enum::from_string",
	"[enum]"
)
{
	CHECK_FALSE(
		fcppt::enum_::from_string<
			test_enum
		>(
			FCPPT_TEXT("xy")
		).has_value()
	);

	CHECK(
		fcppt::test::defer(
			fcppt::enum_::from_string<
				test_enum
			>(
				FCPPT_TEXT("test2")
			)
			==
			fcppt::optional::make(
				test_enum::test2
			)
		)
	);
}
