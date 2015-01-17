//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/matrix/output.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/math/matrix/vector.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <fcppt/config/external_end.hpp>


namespace
{

// ![decl]
typedef
fcppt::math::matrix::static_<
	int,
	2,
	3
>
int_matrix_2x3;

void
ctor()
{
	int_matrix_2x3 const m(
		1,2,3,
		4,5,6
	);

	// Will print: ((1,2,3),(4,5,6))
	std::cout << m << '\n';
}
// ![decl]

// ![identity]
typedef
fcppt::math::matrix::static_<
	int,
	3,
	3
>
int_matrix_3x3;

void
identity()
{
	auto const m(
		int_matrix_3x3::identity()
	);

	std::cout << m << '\n';
}
// ![identity]

// ![iterate]
void
iterate()
{
	auto const m(
		int_matrix_3x3::identity()
	);

	// Will output: 1,0,0,0,1,0,0,0,1,
	for(
		auto const &elem
		:
		m
	)
		std::cout << elem << ",";
}
// ![iterate]

// ![row_iterate]
void
row_iterate()
{
	auto const m(
		int_matrix_3x3::identity()
	);

	// Will output: (1,0,0),(0,1,0),(0,0,1),
	for(
		int_matrix_3x3::size_type row = 0;
		row < m.rows();
		++row
	)
		std::cout << m[row] << ",";
}
// ![row_iterate]

}

int
main()
{
	ctor();

	identity();

	iterate();

	std::cout << '\n';

	row_iterate();

	std::cout << '\n';
}
