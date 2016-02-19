//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/no_init.hpp>
#include <fcppt/cast/int_to_float_fun.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/vector/arithmetic.hpp>
#include <fcppt/math/vector/componentwise_equal.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Wfloat-equal)
#include <fcppt/math/vector/comparison.hpp>
FCPPT_PP_POP_WARNING
#include <fcppt/math/vector/construct.hpp>
#include <fcppt/math/vector/length.hpp>
#include <fcppt/math/vector/narrow_cast.hpp>
#include <fcppt/math/vector/null.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/math/vector/structure_cast.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <iostream>
#include <fcppt/config/external_end.hpp>


namespace
{

namespace tmp
{
// ![vector2f]
typedef
fcppt::math::vector::object<
	float,
	2,
	std::array<
		float,
		2
	>
>
vector2f;
// ![vector2f]
}

// ![vector2f_short]
typedef
fcppt::math::vector::static_<
	float,
	2
>
vector2f;
// ![vector2f_short]

void
init()
{
// ![init]

	// v1 is not initialized
	vector2f v1(
		fcppt::no_init{}
	);

	v1[0] = 0.1f;
	v1[1] = 0.2f;

	// same as v1
	vector2f const v2(
		0.1f,
		0.2f
	);
// ![init]

	std::cout << v1 << ' ' << v2 << '\n';
}

void
convert()
{
// ![convert]
	fcppt::math::vector::static_<
		int,
		1
	> const i(
		10
	);

	auto const f(
		fcppt::math::vector::structure_cast<
			fcppt::math::vector::static_<
				float,
				1
			>,
			fcppt::cast::int_to_float_fun
		>(
			i
		)
	);
// ![convert]

	std::cout << f << '\n';
}


void
construct_narrow()
{
// ![construct_narrow]
	fcppt::math::vector::static_<
		int,
		1
	> const small(
		10
	);
	// Convert smaller to bigger. Only works for N and N+1 and we have to
	// specify the additional element.
	fcppt::math::vector::static_<
		int,
		2
	> const bigger(
		fcppt::math::vector::construct(
			small,
			20
		)
	);

	// Convert bigger to smaller
	auto const small_again(
		fcppt::math::vector::narrow_cast<
			fcppt::math::vector::static_<
				int,
				1
			>
		>(
			bigger
		)
	);
// ![construct_narrow]

	std::cout << small_again << '\n';
}

void
null()
{
// ![null]
	auto const n(
		fcppt::math::vector::null<
			vector2f
		>()
	);
// ![null]
	std::cout << n << '\n';
}

void
comparison()
{
// ![comparison]
	vector2f const x(1.f,2.f);

	vector2f const y(1.f,2.f);

	std::cout << (x == y) << ',' << (x - y == vector2f{0.f,0.f}) << '\n';
// ![comparison]
}

void
comparison_length()
{
// ![comparison_length]
	vector2f const x(1.f,2.f);
	vector2f const y(1.f,2.f);

	float const epsilon(0.001f);

	std::cout << (fcppt::math::vector::length(x - y) < epsilon) << '\n';
// ![comparison_length]
}

void
comparison_range()
{
// ![comparison_range]
	vector2f const x(1.f,2.f);
	vector2f const y(1.f,2.f);

	float const epsilon(0.001f);

	std::cout << fcppt::math::vector::componentwise_equal(x,y,epsilon) << '\n';
// ![comparison_range]
}

// ![asymmetric_div_decl]
// Just for exposition only
struct meter
{
};

struct second
{
};

struct speed
{
};

speed
operator/(
	meter,
	second
)
{
	return
		speed{};
}
// ![asymmetric_div_decl]

void
asymmetric_div()
{
// ![asymmetric_div]
	typedef
	fcppt::math::vector::static_<
		meter,
		2
	>
	meter2;

	typedef
	fcppt::math::vector::static_<
		second,
		2
	>
	second2;

	typedef
	fcppt::math::vector::static_<
		speed,
		2
	>
	speed2;

	speed2 const s(
		meter2(
			meter{},
			meter{}
		)
		/
		second2(
			second{},
			second{}
		)
	);
// ![asymmetric_div]

	static_cast<void>(s);
}

}

int
main()
{
	init();

	convert();

	construct_narrow();

	null();

	comparison();

	comparison_length();

	comparison_range();

	asymmetric_div();
}
