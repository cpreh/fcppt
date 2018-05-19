//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/assert/optional_error.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"assert_optional_error",
	"[assert]"
)
{
	typedef
	fcppt::optional::object<
		int
	>
	optional_int;

	typedef
	fcppt::unique_ptr<
		int
	>
	int_unique_ptr;

	typedef
	fcppt::optional::object<
		int_unique_ptr
	>
	optional_int_unique_ptr;

	CHECK(
		FCPPT_ASSERT_OPTIONAL_ERROR(
			optional_int(
				42
			)
		)
		==
		42
	);

	CHECK(
		*FCPPT_ASSERT_OPTIONAL_ERROR(
			optional_int_unique_ptr(
				fcppt::make_unique_ptr<
					int
				>(
					10
				)
			)
		)
		==
		10
	);

	{
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

		CHECK(
			*ptr_ref
			==
			42
		);
	}
}
