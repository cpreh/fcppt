//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/dim/static.hpp>
#include <fcppt/math/vector/arithmetic.hpp>
#include <fcppt/math/vector/dim.hpp>
#include <fcppt/math/vector/dot.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/type_traits/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <ostream>
#include <fcppt/config/external_end.hpp>


int
main()
{
// ![vector_dim_decl]
	using
	float3_vec
	=
	fcppt::math::vector::static_<
		float,
		3
	>;

	float3_vec vec2(
		10.F, // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
		20.F, // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
		30.F // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
	);
// ![vector_dim_decl]

	float3_vec const vec1(
		1.F, // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
		2.F, // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
		3.F // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
	);

	// add two vectors
	vec2 += vec1;

	std::cout << vec2 << '\n';

	// multiply by a scalar
	vec2 *= 0.5F; // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)

	std::cout << vec2 << '\n';

// ![vector_dim]
	using
	float3_dim
	=
	fcppt::math::dim::static_<
		float,
		3
	>;

	float3_dim const dim(
		1.4F, // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
		1.5F, // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
		1.6F // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
	);

	// dims can be added to or subtracted from vectors
	std::cout << (vec2 - dim) << '\n';
// ![vector_dim]

	// Computes the dot product of two vectors
	fcppt::type_traits::value_type<
		float3_vec
	> const dotp(
		fcppt::math::vector::dot(
			vec1,
			vec2
		)
	);

	std::cout << dotp << '\n';
}
//]
