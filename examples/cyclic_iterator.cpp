//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[cyclic_iterator
#include <fcppt/cyclic_iterator.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <ostream>
#include <vector>
#include <fcppt/config/external_end.hpp>

int main()
{
	typedef std::vector<
		int
	> int_vector;

	// typedef a cyclic_iterator over int_vector::const_iterator
	typedef fcppt::cyclic_iterator<
		int_vector::const_iterator
	> const_cyclic_iterator;

	int_vector ints;

	ints.push_back(1);
	ints.push_back(2);

	const_cyclic_iterator it(
		ints.begin(), // start position of the iterator
		ints.begin(), // start of the container
		ints.end() // end of the container
	);

	for(
		unsigned i = 0;
		i < 6;
		++i
	)
		// printfs 1, 2, 1, 2, 1, 2,
		std::cout
			<< *it++
			<< ", ";

	std::cout << '\n';
}
//]
