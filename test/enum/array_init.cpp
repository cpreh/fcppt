//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/cast/enum_to_int.hpp>
#include <fcppt/enum/array.hpp>
#include <fcppt/enum/array_init.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


namespace
{

enum class my_enum
{
	test1,
	test2,
	test3,
	fcppt_maximum = test3
};

}


TEST_CASE(
	"enum::array_init",
	"[enum]"
)
{
	using
	my_array
	=
	fcppt::enum_::array<
		my_enum,
		int
	>;

	auto const array(
		fcppt::enum_::array_init<
			my_array
		>(
			[](
				auto const _enum
			)
			{
				return
					fcppt::cast::enum_to_int<
						int
					>(
						_enum()
					);
			}
		)
	);

	CHECK(
		array[
			my_enum::test1
		]
		==
		0
	);

	CHECK(
		array[
			my_enum::test2
		]
		==
		1
	);

	CHECK(
		array[
			my_enum::test3
		]
		==
		2
	);
}
