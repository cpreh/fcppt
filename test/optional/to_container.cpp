//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/optional/to_container.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"optional::to_container",
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
		int
	>
	int_vector;

	CHECK(
		fcppt::optional::to_container<
			int_vector
		>(
			optional_int{
				42
			}
		)
		==
		int_vector{
			42
		}
	);

	CHECK(
		fcppt::optional::to_container<
			int_vector
		>(
			optional_int{}
		)
		==
		int_vector{}
	);
}

TEST_CASE(
	"optional::to_container move",
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
	optional_int;

	typedef
	std::vector<
		int_unique_ptr
	>
	int_vector;

	SECTION(
		"success"
	)
	{
		int_vector const vec1{
			fcppt::optional::to_container<
				int_vector
			>(
				optional_int{
					fcppt::make_unique_ptr<
						int
					>(
						42
					)
				}
			)
		};

		REQUIRE(
			vec1.size()
			==
			1u
		);

		CHECK(
			*vec1[0]
			==
			42
		);
	}

	SECTION(
		"failure"
	)
	{
		CHECK(
			fcppt::optional::to_container<
				int_vector
			>(
				optional_int{}
			).empty()
		);
	}
}
