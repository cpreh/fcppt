//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/cast/enum_to_int.hpp>
#include <fcppt/enum/array.hpp>
#include <fcppt/enum/array_init.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
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


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	enum_array_init
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::enum_::array<
		my_enum,
		int
	>
	my_array;

	my_array const array(
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

	BOOST_CHECK_EQUAL(
		array[
			my_enum::test1
		],
		0
	);

	BOOST_CHECK_EQUAL(
		array[
			my_enum::test3
		],
		2
	);
}
