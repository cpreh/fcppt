//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/algorithm/map_optional.hpp>
#include <fcppt/catch/movable.hpp>
#include <fcppt/container/make.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"algorithm map_optional",
	"[algorithm_map_optional]",
)
{
	typedef
	std::vector<
		int
	>
	int_vector;

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

	CHECK(
		fcppt::algorithm::map_optional<
			int_movable_vector
		>(
			int_vector{
				1,
				2,
				3
			},
			[](
				int const _value
			)
			{
				typedef
				fcppt::optional::object<
					int_movable
				>
				optional_int_movable;

				return
					_value
					==
					1
					?
						optional_int_movable{
							int_movable{
								_value
							}
						}
					:
						optional_int_movable{}
					;
			}
		)
		==
		fcppt::container::make<
			int_movable_vector
		>(
			int_movable{
				1
			}
		)
	);
}
