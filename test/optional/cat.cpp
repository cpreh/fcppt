//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/container/make.hpp>
#include <fcppt/optional/cat.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"optional::cat",
	"[optional]"
)
{
	typedef
	fcppt::optional::object<
		int
	>
	optional_int;

	typedef
	std::vector<
		optional_int
	>
	optional_int_vector;

	typedef
	std::vector<
		int
	>
	int_vector;

	CHECK(
		fcppt::optional::cat<
			int_vector
		>(
			optional_int_vector{
				optional_int{
					42
				},
				optional_int{}
			}
		)
		==
		int_vector{
			42
		}
	);
}

TEST_CASE(
	"Optional::cat move",
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

	typedef
	std::vector<
		optional_int_unique_ptr
	>
	optional_int_unique_ptr_vector;

	typedef
	std::vector<
		int_unique_ptr
	>
	int_unique_ptr_vector;

	int_unique_ptr_vector const result(
		fcppt::optional::cat<
			int_unique_ptr_vector
		>(
			fcppt::container::make<
				optional_int_unique_ptr_vector
			>(
				optional_int_unique_ptr(
					fcppt::make_unique_ptr<
						int
					>(
						42
					)
				),
				optional_int_unique_ptr()
			)
		)
	);

	REQUIRE(
		result.size()
		==
		1u
	);

	CHECK(
		*result[0]
		==
		42
	);
}
