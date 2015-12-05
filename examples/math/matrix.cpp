//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_int_range_count.hpp>
#include <fcppt/math/matrix/arithmetic.hpp>
#include <fcppt/math/matrix/identity.hpp>
#include <fcppt/math/matrix/output.hpp>
#include <fcppt/math/matrix/row.hpp>
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
		fcppt::math::matrix::row(
			1,2,3
		),
		fcppt::math::matrix::row(
			4,5,6
		)
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
		fcppt::math::matrix::identity<
			int_matrix_3x3
		>()
	);

	std::cout << m << '\n';
}
// ![identity]

// ![row_iterate]
void
row_iterate()
{
	auto const m(
		fcppt::math::matrix::identity<
			int_matrix_3x3
		>()
	);

	// Will output: (1,0,0),(0,1,0),(0,0,1),
	for(
		auto const row
		:
		fcppt::make_int_range_count(
			m.rows()
		)
	)
		std::cout << m[row] << ",";
}
// ![row_iterate]

// ![arithmetic_mul]
void
multiply()
{
	fcppt::math::matrix::static_<
		int,
		2,
		3
	> const result(
		fcppt::math::matrix::static_<
			int,
			2,
			4
		>(
			fcppt::math::matrix::row(
				1,2,3,4
			),
			fcppt::math::matrix::row(
				2,3,4,5
			)
		)
		*
		fcppt::math::matrix::static_<
			int,
			4,
			3
		>(
			fcppt::math::matrix::row(
				1,2,3
			),
			fcppt::math::matrix::row(
				4,5,6
			),
			fcppt::math::matrix::row(
				7,8,9
			),
			fcppt::math::matrix::row(
				10,11,12
			)
		)
	);

	std::cout << result << '\n';
}
// ![arithmetic_mul]

// ![arithmetic_vector]
void
vector_multiply()
{
	fcppt::math::vector::static_<
		int,
		2
	> const result(
		fcppt::math::matrix::static_<
			int,
			2,
			3
		>(
			fcppt::math::matrix::row(
				1,2,3
			),
			fcppt::math::matrix::row(
				4,5,6
			)
		)
		*
		fcppt::math::vector::static_<
			int,
			3
		>(
			7,8,9
		)
	);

	std::cout << result << '\n';
}
// ![arithmetic_vector]
}

int
main()
{
	ctor();

	identity();

	std::cout << '\n';

	row_iterate();

	std::cout << '\n';

	multiply();

	vector_multiply();
}
