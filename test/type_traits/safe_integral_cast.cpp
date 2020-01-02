//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/type_traits/safe_integral_cast.hpp>
#include <fcppt/type_traits/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


int
main()
{
	typedef
	std::integral_constant<
		int,
		2
	>
	integral;

	typedef
	fcppt::type_traits::safe_integral_cast<
		unsigned,
		integral
	>
	result;

	static_assert(
		std::is_same_v<
			fcppt::type_traits::value_type<
				result
			>,
			unsigned
		>
	);

	static_assert(
		result::value
		==
		2u
	);
}
