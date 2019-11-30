//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/type_traits/to_bool.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


int
main()
{
	static_assert(
		fcppt::type_traits::to_bool<
			std::integral_constant<
				int,
				3
			>
		>::value
	);

	static_assert(
		!fcppt::type_traits::to_bool<
			std::integral_constant<
				int,
				0
			>
		>::value
	);
}
