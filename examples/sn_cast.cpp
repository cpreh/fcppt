//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[sncast
#include <fcppt/sn_cast.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/text.hpp>

int main()
{
	// we can convert an int into a long
	fcppt::io::cout << fcppt::sn_cast<long>(42) << FCPPT_TEXT('\n');

	// we can also convert an int into a float
	fcppt::io::cout << fcppt::sn_cast<float>(42) << FCPPT_TEXT('\n');

	// floats can be converted to floats or greater size
	fcppt::io::cout << fcppt::sn_cast<double>(3.5f) << FCPPT_TEXT('\n');
}

//]
