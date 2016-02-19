//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/extract_from_string.hpp>
#include <fcppt/extract_from_string_error.hpp>
#include <fcppt/extract_from_string_exn.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


namespace
{

bool
check_exception(
	fcppt::extract_from_string_error const &
)
{
	return
		true;
}

}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	extract_from_string
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::optional::object<
		int
	>
	opt_int;

	opt_int const int_val(
		fcppt::extract_from_string<
			int
		>(
			fcppt::string(
				FCPPT_TEXT("42")
			)
		)
	);

	BOOST_CHECK_EQUAL(
		int_val,
		opt_int(
			42
		)
	);

	BOOST_REQUIRE_EXCEPTION(
		fcppt::extract_from_string_exn<
			int
		>(
			fcppt::string(
				FCPPT_TEXT("abc")
			)
		),
		fcppt::extract_from_string_error,
		check_exception
	);
}
