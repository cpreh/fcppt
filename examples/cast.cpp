//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/optional/reference.hpp>
#include <fcppt/cast/float_to_int.hpp>
#include <fcppt/cast/to_unsigned.hpp>
#include <fcppt/cast/try_dynamic.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cassert>
#include <iostream>
#include <ostream>
#include <fcppt/config/external_end.hpp>


namespace
{

void
float_to_int()
{
// ![float_to_int]
	float const f(
		3.5f
	);

	int const i(
		fcppt::cast::float_to_int<
			int
		>(
			f
		)
	);

	// prints 3
	std::cout
		<< i
		<< '\n';
// ![float_to_int]
}

// ![to_unsigned]
template<
	typename T
>
void
test(
	T const _t
)
{
	std::cout
		<<
		fcppt::cast::to_unsigned(
			_t
		)
		<< '\n';
}

void
g()
{
	test(
		4
	);

	// error
	/*
	test(
		4u
	);*/
}
// ![to_unsigned]

//! [try_dynamic]

namespace
{

struct base
{
	virtual ~base()
	{}
};

struct derived1
:
	base
{
};

struct derived2
:
	base
{
};

void
f()
{
	derived1 d1;

	base &base_ref(
		d1
	);

	fcppt::optional::reference<
		derived2
	> const to_d2{
		fcppt::cast::try_dynamic<
			derived2
		>(
			base_ref
		)
	};

	assert(
		!to_d2.has_value()
	);

	fcppt::optional::reference<
		derived1
	> const to_d1{
		fcppt::cast::try_dynamic<
			derived1
		>(
			base_ref
		)
	};

	assert(
		to_d1.has_value()
	);
}

}
//! [try_dynamic]

}

int
main()
{
	float_to_int();

	f();

	g();
}
