//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/join.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/optional/output.hpp>
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
	optional_join
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::optional::object<
		std::string
	>
	optional_string;

	typedef
	fcppt::optional::object<
		optional_string
	>
	optional_optional_string;

	BOOST_CHECK_EQUAL(
		fcppt::optional::join(
			optional_optional_string(
				optional_string(
					"test2"
				)
			)
		),
		optional_string(
			"test2"
		)
	);

	BOOST_CHECK_EQUAL(
		fcppt::optional::join(
			optional_optional_string()
		),
		optional_string()
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	optional_join_move
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::optional::object<
		fcppt::unique_ptr<
			int
		>
	>
	optional_ptr;

	typedef
	fcppt::optional::object<
		optional_ptr
	>
	optional_optional_ptr;

	BOOST_CHECK_EQUAL(
		*fcppt::optional::join(
			optional_optional_ptr(
				optional_ptr(
					fcppt::make_unique_ptr<
						int
					>(
						42
					)
				)
			)
		).get_unsafe(),
		42
	);
}
