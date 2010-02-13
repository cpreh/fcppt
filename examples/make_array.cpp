//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

//[make_array
#include <fcppt/assign/make_array.hpp>

int main()
{
	std::tr1::array<int,3> a(
		fcppt::assign::make_array<int>
			(
				3)
			(
				4)
			(
				5));
}
//]
