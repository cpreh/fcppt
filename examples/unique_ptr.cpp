//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/shared_ptr_impl.hpp>
#include <fcppt/text.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/config/external_begin.hpp>
#include <memory>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace
{

//! [unique_ptr_factory]
typedef std::unique_ptr<
	int
> unique_int_ptr;

// Create a unique_ptr factory
unique_int_ptr
int_ptr_factory()
{
	// make_unique_ptr is a factory function to make a unique_ptr
	// An rvalue is returned here, so no moving is necessary.
	return
		fcppt::make_unique_ptr<
			int
		>(
			42
		);
}
//! [unique_ptr_factory]

//! [unique_ptr_factory_use]
void
int_ptr_arg(
	unique_int_ptr ptr
)
{
	fcppt::io::cout()
		<< *ptr
		<< FCPPT_TEXT('\n');
}

void
test()
{
	// moving unique_ptrs from rvalues works out of the box
	int_ptr_arg(
		int_ptr_factory()
	);
}
//! [unique_ptr_factory_use]


//! [unique_ptr_move]
unique_int_ptr
test2()
{
	// ptr is a named object
	unique_int_ptr ptr(
		fcppt::make_unique_ptr<
			int
		>(
			42
		)
	);

	// ptr must be moved here to take ownership away from it
	return
		std::move(
			ptr
		);
}
//! [unique_ptr_move]

//! [unique_ptr_move_dangerous]
void
test3()
{
	unique_int_ptr ptr(
		fcppt::make_unique_ptr<
			int
		>(
			42
		)
	);

	// Implicit move is not allowed
	/*
	int_ptr_arg(
		ptr
	);
	*/

	// Make the move explicit
	int_ptr_arg(
		std::move(
			ptr
		)
	);

	// ptr is now the null pointer
	fcppt::io::cout()
		<< ptr.get()
		<< FCPPT_TEXT('\n');
}
//! [unique_ptr_move_dangerous]
}

namespace
{
typedef fcppt::shared_ptr<
	int
> shared_int_ptr;

shared_int_ptr const
to_shared_ptr(
	unique_int_ptr ptr
)
{
	// fcppt::shared_ptr can take a unique_ptr,
	// but because ptr is an lvalue, we have to move it
	// note: move is found via ADL
	return
		shared_int_ptr(
			std::move(
				ptr
			)
		);
}


}

namespace
{

struct base
{
	virtual ~base()
	{
	}
};

struct dervied
:
	base
{
};

void
test4()
{
	typedef std::unique_ptr<
		base
	> base_ptr;

	base_ptr foo(
		fcppt::make_unique_ptr<
			dervied
		>()
	);
}

}

int main()
{
	::test();

	::test2();

	::to_shared_ptr(
		::int_ptr_factory()
	);

	::test3();

	::test4();
}
