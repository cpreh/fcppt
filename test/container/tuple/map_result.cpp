//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/use.hpp>
#include <fcppt/container/tuple/map_result.hpp>
#include <fcppt/config/external_begin.hpp>
#include <tuple>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


int
main()
{
	auto const function(
		[](
			auto const _arg
		)
		{
			return
				std::integral_constant<
					int,
					std::remove_const_t<
						decltype(
							_arg
						)
					>::value
					+
					1U
				>{};
		}
	);

	static_assert(
		std::is_same_v<
			fcppt::container::tuple::map_result<
				std::tuple<
					std::integral_constant<
						int,
						1
					>,
					std::integral_constant<
						int,
						2
					>
				>,
				decltype(
					function
				)
			>,
			std::tuple<
				std::integral_constant<
					int,
					2
				>,
				std::integral_constant<
					int,
					3
				>
			>
		>
	);

	FCPPT_USE(
		function
	);
}
