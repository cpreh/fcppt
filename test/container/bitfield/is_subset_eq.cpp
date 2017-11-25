//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/bitfield/enum_object.hpp>
#include <fcppt/container/bitfield/is_subset_eq.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	container_bitfield_is_subset_eq
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

	BOOST_CHECK(
		fcppt::container::bitfield::is_subset_eq(
			field1,
			field2
		)
	);

	BOOST_CHECK(
		fcppt::container::bitfield::is_subset_eq(
			field2,
			field1
		)
	);

	field2[
		test_enum::test1
	] = true;

	BOOST_CHECK(
		fcppt::container::bitfield::is_subset_eq(
			field1,
			field2
		)
	);

	field1[
		test_enum::test2
	] = true;

	BOOST_CHECK(
		!fcppt::container::bitfield::is_subset_eq(
			field1,
			field2
		)
	);
}
