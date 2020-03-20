//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_ref.hpp>
#include <fcppt/nonmovable.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/reference_to_base.hpp>
#include <fcppt/text.hpp>
#include <fcppt/cast/bad_dynamic.hpp>
#include <fcppt/cast/dynamic_exn.hpp>
#include <fcppt/io/cout.hpp>


namespace
{

//! [dynamic_exn]
struct base
{
	FCPPT_NONMOVABLE(base);

	base() = default;

	virtual
	~base() = default;
};

struct derived1
:
	base
{
	FCPPT_NONMOVABLE(derived1);

	derived1() = default;

	~derived1()
	override = default;
};

struct derived2
:
	base
{
	FCPPT_NONMOVABLE(derived2);

	~derived2()
	override = default;
};

void
f(
	fcppt::reference<base> const _base
)
{
	try
	{
		// try to cast _base into a d2
		derived2 &d2(
			fcppt::cast::dynamic_exn<derived2 &>(
				_base.get()
			)
		);

		fcppt::io::cout()
			<< &d2
			<< FCPPT_TEXT('\n');
	}
	catch(fcppt::cast::bad_dynamic const &_error)
	{
		// shows a nice message with the types in it
		fcppt::io::cout()
			<< _error.string()
			<< FCPPT_TEXT('\n');
	}
}
//! [dynamic_exn]

}

int
main()
{
	derived1 d1;

	f(
		fcppt::reference_to_base<
			base
		>(
			fcppt::make_ref(
				d1
			)
		)
	);
}
