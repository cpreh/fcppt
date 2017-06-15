//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/vector/bit_strings.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <iostream>
#include <fcppt/config/external_end.hpp>


int
main()
{
// ![bit_strings]
	typedef
	fcppt::math::vector::static_<
		int,
		3
	>
	vector3;

	// In dimension 3, we have 2^3=8 vectors, so typedef an array of this size
	// here:

	typedef
	std::array<
		vector3,
		8
	>
	binary_vectors;

	binary_vectors const vs(
		fcppt::math::vector::bit_strings<
			int,
			3
		>()
	);

	// Outputs 0,0,0
	std::cout << vs[0];

	// Outputs 0,0,1
	std::cout << vs[1];

	// ...
// ![bit_strings]
}
