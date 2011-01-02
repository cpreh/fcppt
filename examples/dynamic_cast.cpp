//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[dynamiccast

#include <fcppt/bad_dynamic_cast.hpp>
#include <fcppt/dynamic_cast.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/text.hpp>

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

	try
	{
		// try to cast d1 into a d2, which will fail
		derived2 &d2(
			fcppt::dynamic_cast_<
				derived2 &
			>(
				d1
			)
		);

		fcppt::io::cout << &d2 << FCPPT_TEXT('\n');
	}
	catch(
		fcppt::bad_dynamic_cast const &e
	)
	{
		// shows a nice message with the types in it
		fcppt::io::cout
			<< e.string()
			<< FCPPT_TEXT('\n');
	}
}

}
//]

//[trydynamiccast
#include <fcppt/try_dynamic_cast.hpp>

namespace
{

void
g()
{
	derived1 d1;

	base &b(
		d1
	);

	// try to donvert &b into a pointer to derived1 const
	// and declare a new variable named ptr to hold the result
	FCPPT_TRY_DYNAMIC_CAST(
		derived1 const *,
		ptr,
		&b
	)
		fcppt::io::cout
			<< ptr
			<< FCPPT_TEXT('\n');
}

}
//]

int main()
{
	f();

	g();
}
