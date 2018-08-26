//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_int_range_count.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/container/grid/object.hpp>
#include <fcppt/container/grid/resize.hpp>
#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/math/dim/comparison.hpp>
#include <fcppt/math/dim/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"container::grid::resize",
	"[container],[grid]"
)
{
	typedef
	fcppt::container::grid::object<
		std::pair<
			fcppt::container::grid::size_type,
			fcppt::container::grid::size_type
		>,
		2
	>
	sz_pair_grid;

	sz_pair_grid const test{
		fcppt::container::grid::resize(
			sz_pair_grid{
				sz_pair_grid::dim(
					5u,
					10u
				),
				[](
					sz_pair_grid::pos const _pos
				)
				{
					return
						std::make_pair(
							fcppt::cast::size<
								fcppt::container::grid::size_type
							>(
								_pos.x()
							),
							fcppt::cast::size<
								fcppt::container::grid::size_type
							>(
								_pos.y()
							)
						);
				}
			},
			sz_pair_grid::dim(
				10u,
				15u
			),
			[](
				sz_pair_grid::pos
			)
			{
				return
					sz_pair_grid::value_type(
						10u,
						20u
					);
			}
		)
	};

	REQUIRE(
		test.size()
		==
		sz_pair_grid::dim(
			10u,
			15u
		)
	);

	for(
		auto const y
		:
		fcppt::make_int_range_count(
			test.size().h()
		)
	)
		for(
			auto const x
			:
			fcppt::make_int_range_count(
				test.size().w()
			)
		)
		{
			if(
				x < 5 && y < 10
			)
				CHECK(
					test.get_unsafe(
						sz_pair_grid::pos(
							x,
							y
						)
					)
					==
					std::make_pair(
						fcppt::cast::size<
							fcppt::container::grid::size_type
						>(
							x
						),
						fcppt::cast::size<
							fcppt::container::grid::size_type
						>(
							y
						)
					)
				);
			else
				CHECK(
					test.get_unsafe(
						sz_pair_grid::pos(
							x,
							y
						)
					)
					==
					sz_pair_grid::value_type(
						10u,
						20u
					)
				);
		}
}

TEST_CASE(
	"container::grid::resize move",
	"[container],[grid]"
)
{
	typedef
	fcppt::container::grid::object<
		fcppt::unique_ptr<
			fcppt::container::grid::size_type
		>,
		2
	>
	unique_ptr_grid;

	unique_ptr_grid const test{
		fcppt::container::grid::resize(
			unique_ptr_grid{
				unique_ptr_grid::dim{
					5u,
					10u
				},
				[](
					unique_ptr_grid::pos const _pos
				)
				{
					return
						fcppt::make_unique_ptr<
							fcppt::container::grid::size_type
						>(
							fcppt::cast::size<
								fcppt::container::grid::size_type
							>(
								_pos.x()
								+
								_pos.y()
							)
						);
				}
			},
			unique_ptr_grid::dim{
				10u,
				15u
			},
			[](
				unique_ptr_grid::pos
			)
			{
				return
					fcppt::make_unique_ptr<
						fcppt::container::grid::size_type
					>(
						100u
					);
			}
		)
	};

	for(
		auto const y
		:
		fcppt::make_int_range_count(
			test.size().h()
		)
	)
		for(
			auto const x
			:
			fcppt::make_int_range_count(
				test.size().w()
			)
		)
		{
			if(
				x < 5 && y < 10
			)
				CHECK(
					*test.get_unsafe(
						unique_ptr_grid::pos(
							x,
							y
						)
					)
					==
					x + y
				);
			else
				CHECK(
					*test.get_unsafe(
						unique_ptr_grid::pos(
							x,
							y
						)
					)
					==
					100u
				);
		}
}
