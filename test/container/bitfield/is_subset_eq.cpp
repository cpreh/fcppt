//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/bitfield/enum_object.hpp>
#include <fcppt/container/bitfield/is_subset_eq.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"container::bitfield::is_subset_eq",
	"[container],[bitfield]"
)
{
	enum class test_enum
	{
		test1,
		test2,
		test3,
		fcppt_maximum = test3
	};

	typedef
	fcppt::container::bitfield::enum_object<
		test_enum
	>
	bitfield;

	bitfield field1(
		bitfield::null()
	);

	bitfield field2(
		bitfield::null()
	);

	CHECK(
		fcppt::container::bitfield::is_subset_eq(
			field1,
			field2
		)
	);

	CHECK(
		fcppt::container::bitfield::is_subset_eq(
			field2,
			field1
		)
	);

	field2[
		test_enum::test1
	] = true;

	CHECK(
		fcppt::container::bitfield::is_subset_eq(
			field1,
			field2
		)
	);

	field1[
		test_enum::test2
	] = true;

	CHECK_FALSE(
		fcppt::container::bitfield::is_subset_eq(
			field1,
			field2
		)
	);
}
