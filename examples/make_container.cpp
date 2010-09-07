//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[make_container
#include <fcppt/assign/make_container.hpp>
#include <vector>
#include <set>

int main()
{
	std::vector<int> v(
		fcppt::assign::make_container< std::vector<int> >
			(3)
			(4)
			(5));
	
	std::set<int> s(
		fcppt::assign::make_container< std::set<int> >
			(3)
			(4)
			(5));
}
//]
