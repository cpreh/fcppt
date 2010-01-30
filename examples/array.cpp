//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/assign/make_array.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/text.hpp>
#include <boost/foreach.hpp>

int main()
{
	std::tr1::array<int,3> const a =
		fcppt::assign::make_array<int>(3)(4)(5);

	BOOST_FOREACH(int x,a)
	{
		fcppt::io::cout << x << FCPPT_TEXT('\n');
	}
}
