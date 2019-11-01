//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/metal/interval.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal/list/list.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


int
main()
{
	typedef
	fcppt::metal::interval<
		int,
		3,
		5
	>
	interval;

	static_assert(
		std::is_same_v<
			interval,
			metal::list<
				std::integral_constant<
					int,
					3
				>,
				std::integral_constant<
					int,
					4
				>
			>
		>
	);
}
