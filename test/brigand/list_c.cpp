//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/brigand/list_c.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/sequences/list.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


int
main()
{
	static_assert(
		std::is_same<
			fcppt::brigand::list_c<
				int,
				1,
				2
			>,
			brigand::list<
				std::integral_constant<
					int,
					1
				>,
				std::integral_constant<
					int,
					2
				>
			>
		>::value,
		""
	);
}
