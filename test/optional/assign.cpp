//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/optional/assign.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"optional::assign",
	"[optional]"
)
{
	typedef
	fcppt::optional::object<
		int
	>
	optional_int;

	optional_int test;

	int const &result(
		fcppt::optional::assign(
			test,
			42
		)
	);

	CHECK(
		result
		==
		42
	);
}

TEST_CASE(
	"optional::assign move",
	"[optional]"
)
{
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

	optional_int_unique_ptr test;

	int_unique_ptr const &result(
		fcppt::optional::assign(
			test,
			fcppt::make_unique_ptr<
				int
			>(
				42
			)
		)
	);

	CHECK(
		*result
		==
		42
	);
}
