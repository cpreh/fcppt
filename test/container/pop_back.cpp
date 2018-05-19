//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/assign/make_container.hpp>
#include <fcppt/container/pop_back.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"container::pop_back",
	"[container]"
)
{
	typedef
	std::vector<
		int
	>
	int_vector;

	int_vector empty{};

	CHECK_FALSE(
		fcppt::container::pop_back(
			empty
		).has_value()
	);

	int_vector vec12{
		1,
		2
	};

	CHECK(
		fcppt::container::pop_back(
			vec12
		)
		==
		fcppt::optional::make(
			2
		)
	);

	int_vector const expected{
		1
	};

	CHECK(
		vec12
		==
		expected
	);
}

TEST_CASE(
	"container::pop_back move",
	"[container]"
)
{
	typedef
	fcppt::unique_ptr<
		int
	>
	int_ptr;

	typedef
	std::vector<
		int_ptr
	>
	int_ptr_vector;

	int_ptr_vector vector(
		fcppt::assign::make_container<
			int_ptr_vector
		>(
			fcppt::make_unique_ptr<
				int
			>(
				42
			)
		)
	);

	fcppt::optional::maybe(
		fcppt::container::pop_back(
			vector
		),
		[]{
			CHECK(
				false
			);
		},
		[](
			int_ptr &&_ptr
		)
		{
			CHECK(
				*_ptr
				==
				42
			);
		}
	);

	CHECK(
		vector.empty()
	);
}
