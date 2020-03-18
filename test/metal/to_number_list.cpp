//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/metal/to_number_list.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


int
main()
{
	static_assert(
		std::is_same_v<
			fcppt::metal::to_number_list<
				::metal::list<
					std::integral_constant<
						int,
						5 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
					>,
					std::integral_constant<
						int,
						10 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
					>
				>
			>,
			::metal::list<
				metal::number<
					5 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
				>,
				metal::number<
					10 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
				>
			>
		>
	);
}
