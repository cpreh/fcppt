//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/catch/movable.hpp>
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
	fcppt::catch_::movable<
		int
	>
	int_movable;

	typedef
	fcppt::optional::object<
		int_movable
	>
	optional_int_movable;

	typedef
	std::vector<
		int_movable
	>
	int_movable_vector;

	CHECK(
		fcppt::optional::cat<
			int_movable_vector
		>(
			fcppt::container::make<
				std::vector<
					optional_int_movable
				>
			>(
				optional_int_movable{
					int_movable{
						42
					}
				},
				optional_int_movable{}
			)
		)
		==
		fcppt::container::make<
			int_movable_vector
		>(
			int_movable{
				42
			}
		)
	);
}
