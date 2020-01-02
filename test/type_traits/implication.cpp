//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/type_traits/implication.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


int
main()
{
	static_assert(
		std::negation<
			fcppt::type_traits::implication<
				std::true_type,
				std::false_type
			>
		>::value
	);

	static_assert(
		fcppt::type_traits::implication<
			std::false_type,
			std::false_type
		>::value
	);

	static_assert(
		fcppt::type_traits::implication<
			std::false_type,
			std::true_type
		>::value
	);

	static_assert(
		fcppt::type_traits::implication<
			std::true_type,
			std::true_type
		>::value
	);
}
