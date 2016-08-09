//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//! [dynamic_exn]
#include <fcppt/text.hpp>
#include <fcppt/cast/bad_dynamic.hpp>
#include <fcppt/cast/dynamic_exn.hpp>
#include <fcppt/io/cout.hpp>


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
	base &_base
)
{
	try
	{
		// try to cast _base into a d2
		derived2 &d2(
			fcppt::cast::dynamic_exn<
				derived2 &
			>(
				_base
			)
		);

		fcppt::io::cout()
			<< &d2
			<< FCPPT_TEXT('\n');
	}
	catch(
		fcppt::cast::bad_dynamic const &_error
	)
	{
		// shows a nice message with the types in it
		fcppt::io::cout()
			<< _error.string()
			<< FCPPT_TEXT('\n');
	}
}

}
//! [dynamic_exn]

int
main()
{
	derived1 d1;

	f(
		d1
	);
}
