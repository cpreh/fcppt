//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[make_array
#include <fcppt/text.hpp>
#include <fcppt/assign/make_array.hpp>
#include <fcppt/container/array.hpp>
#include <fcppt/io/cout.hpp>


int main()
{
	typedef fcppt::container::array<int,3> array_int3;

	array_int3 const array(
		fcppt::assign::make_array<int>
			(3)
			(4)
			(5)
	);

	for(
		array_int3::const_iterator it(
			array.begin()
		);
		it != array.end();
		++it
	)
		fcppt::io::cout()
			<< *it
			<< FCPPT_TEXT(' '
		);
}
//]
