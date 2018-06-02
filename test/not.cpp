//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/not.hpp>


int
main()
{
	static_assert(
		fcppt::not_(
			true
		)
		==
		false,
		""
	);

	static_assert(
		fcppt::not_(
			false
		)
		==
		true,
		""
	);
}
