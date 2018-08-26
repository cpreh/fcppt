//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/brigand/all_of.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/sequences/list.hpp>
#include <brigand/types/args.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


int
main()
{
	static_assert(
		fcppt::brigand::all_of<
			brigand::list<
				int,
				long
			>,
			std::is_integral<
				brigand::_1
			>
		>::value,
		""
	);

	static_assert(
		!fcppt::brigand::all_of<
			brigand::list<
				float,
				int
			>,
			std::is_integral<
				brigand::_1
			>
		>::value,
		""
	);
}
