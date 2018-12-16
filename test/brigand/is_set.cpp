//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/brigand/is_set.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/sequences/list.hpp>
#include <fcppt/config/external_end.hpp>


int
main()
{
	static_assert(
		fcppt::brigand::is_set<
			brigand::list<
				int,
				float
			>
		>::value,
		""
	);

	static_assert(
		!fcppt::brigand::is_set<
			brigand::list<
				int,
				int
			>
		>::value,
		""
	);
}
