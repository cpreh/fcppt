//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/container/make.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/optional/sequence.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"optional::sequence",
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

	typedef
	fcppt::optional::object<
		int_vector
	>
	result_type;

	{
		result_type const result(
			fcppt::optional::sequence<
				int_vector
			>(
				optional_int_vector{
					optional_int{
						10
					},
					optional_int{
						20
					}
				}
			)
		);

		REQUIRE(
			result.has_value()
		);

		CHECK(
			result.get_unsafe()
			==
			int_vector{
				10,
				20
			}
		);
	}

	{
		CHECK_FALSE(
			fcppt::optional::sequence<
				int_vector
			>(
				optional_int_vector{
					optional_int{
						10
					},
					optional_int{}
				}
			).has_value()
		);
	}
}

TEST_CASE(
	"optional::sequence move",
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


	typedef
	fcppt::optional::object<
		int_unique_ptr_vector
	>
	result_type;

	result_type const result(
		fcppt::optional::sequence<
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
				)
			)
		)
	);

	REQUIRE(
		result.has_value()
	);

	REQUIRE(
		result.get_unsafe().size()
		==
		1u
	);

	CHECK(
		*result.get_unsafe()[0]
		==
		42
	);
}
