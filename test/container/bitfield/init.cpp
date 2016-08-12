//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/bitfield/init.hpp>
#include <fcppt/container/bitfield/object_from_enum.hpp>
#include <fcppt/container/bitfield/object_impl.hpp>
#include <fcppt/container/bitfield/operators.hpp>
#include <fcppt/assert/unreachable.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_bitfield_init
)
{
FCPPT_PP_POP_WARNING

	enum class my_enum
	{
		test1,
		test2,
		test3,
		fcppt_maximum = test3
	};

	typedef
	fcppt::container::bitfield::object_from_enum<
		my_enum
	>
	bitfield;

	bitfield const test(
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

	BOOST_CHECK(
		test
		&
		my_enum::test1
	);

	BOOST_CHECK(
		!(
			test
			&
			my_enum::test2
		)
	);

	BOOST_CHECK(
		test
		&
		my_enum::test3
	);
}
