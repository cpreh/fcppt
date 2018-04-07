//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/array/map.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <iostream>
#include <ostream>
#include <fcppt/config/external_end.hpp>


int
main()
{
//! [array_map]
typedef
std::array<int,3>
three_ints;

three_ints const a{{ 1,2,3 }};

three_ints const b(
	fcppt::container::array::map(
		a,
		[](int const _arg) { return _arg * 3; }
	)
);

// b now contains: 3, 6, 9
//! [array_map]
std::cout << b.empty() << '\n';
}
