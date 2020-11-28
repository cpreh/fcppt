//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/metal/from_number_list.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


int
main()
{
	static_assert(
		std::is_same_v<
			fcppt::metal::from_number_list<
				int,
				::metal::list<
					metal::number<
						5
					>,
					metal::number<
						10
					>
				>
			>,
			::metal::list<
				std::integral_constant<
					int,
					5
				>,
				std::integral_constant<
					int,
					10
				>
			>
		>
	);
}
