//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/assert/unreachable.hpp>
#include <fcppt/container/bitfield/enum_object.hpp>
#include <fcppt/container/bitfield/init.hpp>
#include <fcppt/container/bitfield/operators.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"container::bitfield::init",
	"[container],[bitfield]"
)
{
	enum class my_enum
	{
		test1,
		test2,
		test3,
		fcppt_maximum = test3
	};

	using
	bitfield
	=
	fcppt::container::bitfield::enum_object<
		my_enum
	>;

	auto const test(
		fcppt::container::bitfield::init<
			bitfield
		>(
			[](
				my_enum const _value
			)
			{
				switch(
					_value
				)
				{
				case my_enum::test1:
				case my_enum::test3:
					return
						true;
				case my_enum::test2:
					return
						false;
				}

				FCPPT_ASSERT_UNREACHABLE;
			}
		)
	);

	CHECK(
		test[
			my_enum::test1
		]
	);

	CHECK_FALSE(
		test[
			my_enum::test2
		]
	);

	CHECK(
		test[
			my_enum::test3
		]
	);
}
