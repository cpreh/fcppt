//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/ceil_div_static.hpp>


int
main()
{
	static_assert(
		fcppt::math::ceil_div_static<
			unsigned,
			0U,
			1U
		>::value
		==
		0U
	);

	static_assert(
		fcppt::math::ceil_div_static<
			unsigned,
			1U,
			1U
		>::value
		==
		1U
	);

	static_assert(
		fcppt::math::ceil_div_static<
			unsigned,
			5U, // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
			3U
		>::value
		==
		2U
	);

	static_assert(
		fcppt::math::ceil_div_static<
			unsigned,
			6U, // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
			3U
		>::value
		==
		2U
	);
}
