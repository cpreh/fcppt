//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/cast_to_enum.hpp>
#include <fcppt/exception.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


namespace
{

enum class testenum
{
	enum1,
	enum2,
	size
};

bool
check_function(
	fcppt::exception const &
)
{
	return true;
}

}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	cast_to_enum
)
{
FCPPT_PP_POP_WARNING

	BOOST_CHECK(
		fcppt::cast_to_enum<
			testenum
		>(
			1u
		)
		==
		testenum::enum2
	);

	BOOST_CHECK_EXCEPTION(
		fcppt::cast_to_enum<
			testenum
		>(
			2u
		),
		fcppt::exception,
		check_function
	);
}
