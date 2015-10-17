//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/bit/shift_count.hpp>
#include <fcppt/bit/shifted_mask.hpp>
#include <fcppt/bit/test.hpp>
#include <fcppt/cast/enum_to_int.hpp>
#include <fcppt/container/bitfield/object.hpp>
#include <fcppt/container/bitfield/object_from_enum.hpp>
#include <fcppt/container/bitfield/underlying_value.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_bitfield_underlying_value
)
{
FCPPT_PP_POP_WARNING

	enum class test_enum
	{
		test1,
		test2,
		test3,
		fcppt_maximum = test3
	};

	typedef
	fcppt::container::bitfield::object_from_enum<
		test_enum
	>
	bitfield;

	auto const check_bit(
		[](
			bitfield::internal_type const _value,
			test_enum const _enum
		)
		-> bool
		{
			return
				fcppt::bit::test(
					_value,
					fcppt::bit::shifted_mask<
						bitfield::internal_type
					>(
						fcppt::cast::enum_to_int<
							fcppt::bit::shift_count
						>(
							_enum
						)
					)
				);
		}
	);

	bitfield field1(
		bitfield::null()
	);

	field1[
		test_enum::test2
	] = true;

	bitfield::internal_type const value(
		fcppt::container::bitfield::underlying_value(
			field1
		)
	);

	BOOST_CHECK(
		!check_bit(
			value,
			test_enum::test1
		)
	);

	BOOST_CHECK(
		check_bit(
			value,
			test_enum::test2
		)
	);

	BOOST_CHECK(
		!check_bit(
			value,
			test_enum::test3
		)
	);
}


