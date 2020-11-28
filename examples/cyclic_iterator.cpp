//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/cyclic_iterator.hpp>
#include <fcppt/algorithm/repeat.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <ostream>
#include <vector>
#include <fcppt/config/external_end.hpp>

int
main()
{
//! [cyclic_iterator]
	using
	int_vector
	=
	std::vector<
		int
	>;

	using
	const_cyclic_iterator
	=
	fcppt::cyclic_iterator<
		int_vector::const_iterator
	>;

	int_vector const ints{{
		1, 2
	}};

	const_cyclic_iterator it(
		ints.begin(), // start position of the iterator
		const_cyclic_iterator::boundary{
			ints.begin(), // start of the container
			ints.end() // end of the container
		}
	);

	// prints 1, 2, 1, 2, 1, 2,
	fcppt::algorithm::repeat(
		6,
		[
			&it
		]{
			std::cout
				<< *it++
				<< ", ";
		}
	);

	std::cout << '\n';
//! [cyclic_iterator]
}
