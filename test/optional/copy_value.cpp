//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_cref.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/copy_value.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/optional/reference.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	optional_copy_value
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::optional::reference<
		std::string const
	>
	optional_string_ref;

	std::string const test(
		"test1"
	);

	BOOST_CHECK_EQUAL(
		fcppt::optional::copy_value(
			optional_string_ref{
				fcppt::make_cref(
					test
				)
			}
		),
		fcppt::optional::object<
			std::string
		>(
			std::string(
				"test1"
			)
		)
	);
}
