//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/text.hpp>
#include <fcppt/assert/exception.hpp>
#include <fcppt/assert/throw_message.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


namespace
{

bool
contains_false(
	fcppt::assert_::exception const &_e
)
{
	return
		_e.string().find(
			FCPPT_TEXT("false")
		) != fcppt::string::npos;
}

bool
contains_false_and_contains_1337(
	fcppt::assert_::exception const &_e
)
{
	return
		contains_false(
			_e
		) &&
		_e.string().find(
			FCPPT_TEXT("1337")
		) != fcppt::string::npos;
}

}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	assert
)
{

FCPPT_PP_POP_WARNING

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4127)

	BOOST_REQUIRE_EXCEPTION(
		FCPPT_ASSERT_THROW_MESSAGE(
			false,
			fcppt::assert_::exception,
			FCPPT_TEXT("test")
		),
		fcppt::assert_::exception,
		contains_false
	);

	BOOST_REQUIRE_EXCEPTION(
		FCPPT_ASSERT_THROW_MESSAGE(
			false,
			fcppt::assert_::exception,
			FCPPT_TEXT("1337")
		),
		fcppt::assert_::exception,
		contains_false_and_contains_1337
	);
FCPPT_PP_POP_WARNING
}
