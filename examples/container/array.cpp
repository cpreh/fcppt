//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[array
#include <fcppt/text.hpp>
#include <fcppt/container/array.hpp>
#include <fcppt/io/cout.hpp>


int main()
{
	typedef fcppt::container::array<
		int,
		5
	> int5array;

	// array is a POD so it can be initialized like this
	int5array const array =
	{{
		1, 2, 3, 4, 5
	}};

	for(
		int5array::const_iterator it(
			array.begin()
		);
		it != array.end();
		++it
	)
		fcppt::io::cout()
			<< *it
			<< FCPPT_TEXT(' ');

	fcppt::io::cout()
		<< FCPPT_TEXT('\n');
}
//]
