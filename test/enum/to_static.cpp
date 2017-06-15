//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/enum/to_static.hpp>
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
	enum_to_static
)
{
FCPPT_PP_POP_WARNING

	BOOST_CHECK(
		fcppt::enum_::to_static(
			my_enum::test3,
			[](
				auto const _value
			)
			{
				FCPPT_USE(
					_value
				);

				typedef
				decltype(
					_value
				)
				val;

				return
					val::value
					==
					my_enum::test3;
			}
		)
	);
}
