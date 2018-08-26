//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/brigand/flip_pair.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/sequences/pair.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


int
main()
{
	static_assert(
		std::is_same<
			fcppt::brigand::flip_pair<
				brigand::pair<
					int,
					float
				>
			>,
			brigand::pair<
				float,
				int
			>
		>::value,
		""
	);
}
