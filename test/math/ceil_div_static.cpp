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
			0u,
			1u
		>::value
		==
		0u,
		""
	);

	static_assert(
		fcppt::math::ceil_div_static<
			unsigned,
			1u,
			1u
		>::value
		==
		1u,
		""
	);

	static_assert(
		fcppt::math::ceil_div_static<
			unsigned,
			5u,
			3u
		>::value
		==
		2u,
		""
	);

	static_assert(
		fcppt::math::ceil_div_static<
			unsigned,
			6u,
			3u
		>::value
		==
		2u,
		""
	);
}
