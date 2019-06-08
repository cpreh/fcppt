//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/catch/movable.hpp>
#include <fcppt/container/make.hpp>
#include <fcppt/container/pop_back.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
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

	CHECK(
		fcppt::container::pop_back(
			empty
		)
		==
		fcppt::optional::object<
			int
		>{}
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
	fcppt::catch_::movable<
		int
	>
	int_movable;

	typedef
	std::vector<
		int_movable
	>
	int_movable_vector;

	int_movable_vector vector(
		fcppt::container::make<
			int_movable_vector
		>(
			int_movable{
				42
			}
		)
	);

	CHECK(
		fcppt::container::pop_back(
			vector
		)
		==
		fcppt::optional::make(
			int_movable{
				42
			}
		)
	);

	CHECK(
		vector.empty()
	);
}
