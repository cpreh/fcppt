//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/optional/bind.hpp>
#include <fcppt/optional/object_impl.hpp>
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
	optional_bind
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::optional::object<
		std::string
	>
	optional_string;

	optional_string const opt_string(
		"test1"
	);

	optional_string const &opt_string_ref(
		opt_string
	);

	BOOST_CHECK_EQUAL(
		fcppt::optional::bind(
			optional_string(
				"test2"
			),
			[
				&opt_string_ref
			](
				std::string const &
			)
			{
				return
					opt_string_ref;
			}
		).get_unsafe(),
		"test1"
	);
}
