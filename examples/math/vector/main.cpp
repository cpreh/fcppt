//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/vector/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <iostream>
#include <fcppt/config/external_end.hpp>


namespace
{

void
f()
{
//![array]
	std::array<float, 3> point{{1.f, 2.f, 3.f}};
//![array]

	std::cout << point[0] << '\n';
}

}

int
main()
{
	f();
}
