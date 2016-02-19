//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/optional/object_impl.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


template
class
fcppt::optional::object<
	int
>;

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	optional_general
)
{
FCPPT_PP_POP_WARNING

	typedef fcppt::optional::object<
		std::string
	> optional_string;

	optional_string test;

	BOOST_CHECK(
		!test.has_value()
	);

	test =
		optional_string(
			"test"
		);

	BOOST_REQUIRE(
		test.has_value()
	);

	BOOST_CHECK_EQUAL(
		test.get_unsafe(),
		"test"
	);

	test =
		optional_string();

	BOOST_CHECK(
		!test.has_value()
	);
}
