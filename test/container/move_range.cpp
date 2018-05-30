//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/strong_typedef.hpp>
#include <fcppt/strong_typedef_output.hpp>
#include <fcppt/catch/movable.hpp>
#include <fcppt/container/make.hpp>
#include <fcppt/container/make_move_range.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"container move_range",
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

	FCPPT_MAKE_STRONG_TYPEDEF(
		int_movable,
		strong_int_movable
	);

	typedef
	std::vector<
		strong_int_movable
	>
	strong_int_movable_vector;

	CHECK(
		fcppt::algorithm::map<
			strong_int_movable_vector
		>(
			fcppt::container::make_move_range(
				fcppt::container::make<
					int_movable_vector
				>(
					int_movable{
						0
					},
					int_movable{
						1
					}
				)
			),
			[](
				int_movable &&_value
			)
			{
				return
					strong_int_movable{
						std::move(
							_value
						)
					};
			}
		)
		==
		fcppt::container::make<
			strong_int_movable_vector
		>(
			strong_int_movable{
				int_movable{
					0
				}
			},
			strong_int_movable{
				int_movable{
					1
				}
			}
		)
	);
}
