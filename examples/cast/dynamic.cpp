//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/text.hpp>
#include <fcppt/cast/dynamic.hpp>
#include <fcppt/optional/reference.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <fcppt/config/external_end.hpp>


//! [dynamic]
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
f(
	base &_base
)
{
	fcppt::optional::reference<
		derived2
	> const to_d2{
		fcppt::cast::dynamic<
			derived2
		>(
			_base
		)
	};

	fcppt::optional::reference<
		derived1
	> const to_d1{
		fcppt::cast::dynamic<
			derived1
		>(
			_base
		)
	};

	std::cout
		<< to_d2.has_value()
		<< ' '
		<< to_d1.has_value()
		<< '\n';
}

}
//! [dynamic]

int
main()
{
	derived1 d1;

	f(
		d1
	);
}
