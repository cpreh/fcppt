//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/assert/optional_error.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <memory>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	assert_optional_error
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::optional<
		int
	>
	optional_int;

	typedef
	std::unique_ptr<
		int
	>
	int_unique_ptr;

	typedef
	fcppt::optional<
		int_unique_ptr
	>
	optional_int_unique_ptr;

	BOOST_CHECK(
		FCPPT_ASSERT_OPTIONAL_ERROR(
			optional_int(
				42
			)
		)
		==
		42
	);

	int_unique_ptr const ptr(
		FCPPT_ASSERT_OPTIONAL_ERROR(
			optional_int_unique_ptr(
				fcppt::make_unique_ptr<
					int
				>(
					10
				)
			)
		)
	);

	BOOST_CHECK_EQUAL(
		*ptr,
		10
	);

	optional_int_unique_ptr const opt_ptr(
		fcppt::make_unique_ptr<
			int
		>(
			42
		)
	);

	int_unique_ptr const &ptr_ref(
		FCPPT_ASSERT_OPTIONAL_ERROR(
			opt_ptr
		)
	);

	BOOST_CHECK_EQUAL(
		*ptr_ref,
		42
	);
}
