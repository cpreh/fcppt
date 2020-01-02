//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/catch/movable.hpp>
#include <fcppt/container/array/init.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <array>
#include <cstddef>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"array::init",
	"[container],[array]"
)
{
	typedef
	fcppt::catch_::movable<
		std::size_t
	>
	movable;

	typedef
	std::array<
		movable,
		2
	>
	movable_2_array;

	CHECK(
		fcppt::container::array::init<
			movable_2_array
		>(
			[](
				auto const _index
			){
				return
					movable{
						_index()
					};
			}
		)
		==
		movable_2_array{{
			movable{
				0u
			},
			movable{
				1u
			}
		}}
	);
}
