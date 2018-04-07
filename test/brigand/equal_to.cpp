//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/brigand/equal_to.hpp>
#include <fcppt/brigand/list_c.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


int
main()
{
	static_assert(
		fcppt::brigand::equal_to<
			fcppt::brigand::list_c<
				int,
				1,
				2
			>,
			fcppt::brigand::list_c<
				int,
				1,
				2
			>
		>::value,
		"Lists not equal"
	);

	static_assert(
		not
		fcppt::brigand::equal_to<
			fcppt::brigand::list_c<
				int,
				3,
				2
			>,
			fcppt::brigand::list_c<
				int,
				1,
				2
			>
		>::value,
		"Lists equal"
	);
}
