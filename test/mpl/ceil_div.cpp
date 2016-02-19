//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/mpl/ceil_div.hpp>


int
main()
{
	static_assert(
		fcppt::mpl::ceil_div<
			unsigned,
			0u,
			1u
		>::value
		==
		0u,
		""
	);

	static_assert(
		fcppt::mpl::ceil_div<
			unsigned,
			1u,
			1u
		>::value
		==
		1u,
		""
	);

	static_assert(
		fcppt::mpl::ceil_div<
			unsigned,
			5u,
			3u
		>::value
		==
		2u,
		""
	);

	static_assert(
		fcppt::mpl::ceil_div<
			unsigned,
			6u,
			3u
		>::value
		==
		2u,
		""
	);
}
