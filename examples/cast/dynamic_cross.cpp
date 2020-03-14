//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_ref.hpp>
#include <fcppt/nonmovable.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/cast/dynamic_cross.hpp>
#include <fcppt/optional/reference.hpp>
#include <fcppt/preprocessor/disable_clang_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <fcppt/config/external_end.hpp>


//! [dynamic_cross]
namespace
{

struct base
{
	FCPPT_NONMOVABLE(
		base
	);

	base()
	= default;

	virtual
	~base()
	= default;
};

struct derived1
:
	base
{
	FCPPT_NONMOVABLE(
		derived1
	);

	derived1()
	= default;

	~derived1()
	override
	= default;
};

struct derived2
:
	base
{
	FCPPT_NONMOVABLE(
		derived2
	);

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_CLANG_WARNING(-Wunused-member-function)
	derived2()
	= default;
FCPPT_PP_POP_WARNING

	~derived2()
	override
	= default;
};

void
f(
	fcppt::reference<
		derived1
	> const _d1
)
{
	fcppt::optional::reference<
		derived2
	> const to_d2(
		fcppt::cast::dynamic_cross<
			derived2
		>(
			_d1.get()
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
	derived1 d1{};

	f(
		fcppt::make_ref(
			d1
		)
	);
}
