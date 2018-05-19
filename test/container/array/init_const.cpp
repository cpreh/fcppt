//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/noncopyable.hpp>
#include <fcppt/container/array/init_const.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <array>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"array::init_const",
	"[container],[array]"
)
{
	typedef
	std::array<
		int,
		2
	>
	int_2_array;

	CHECK(
		fcppt::container::array::init_const<
			int_2_array
		>(
			42
		)
		==
		int_2_array{{
			42,
			42
		}}
	);
}
