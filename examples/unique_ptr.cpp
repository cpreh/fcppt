//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[unique_ptr_factory
#include <fcppt/unique_ptr.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/text.hpp>

//<--
namespace
{
//-->

typedef fcppt::unique_ptr<
	int
> unique_int_ptr;

// create a unique_ptr factory
unique_int_ptr
int_ptr_factory()
{
	// make_unique_ptr is a factory function to make unique_ptr
	// note: an rvalue is returned here
	return 
		fcppt::make_unique_ptr<
			int
		>(
			42
		);
}

// make a function that
void
int_ptr_arg(
	unique_int_ptr ptr
)
{
	fcppt::io::cout
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
//]

}

//[unique_ptr_shared_ptr

#include <fcppt/shared_ptr.hpp>
#include <fcppt/move.hpp>

//<--
namespace
{
//-->

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
	// note: that move is found via ADL
	return
		shared_int_ptr(
			move(
				ptr
			)
		);
}

//]

}

int main()
{
}
