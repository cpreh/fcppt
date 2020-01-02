//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/cast/dynamic_cross.hpp>
#include <fcppt/optional/reference.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <fcppt/config/external_end.hpp>


//! [dynamic_cross]
namespace
{

struct base
{
	virtual
	~base()
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
	derived1 &_d1
)
{
	fcppt::optional::reference<
		derived2
	> const to_d2(
		fcppt::cast::dynamic_cross<
			derived2
		>(
			_d1
		)
	);

	std::cout
		<< to_d2.has_value()
		<< '\n';
}

}
//! [dynamic_cross]

int
main()
{
	derived1 d1;

	f(
		d1
	);
}
