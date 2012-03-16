//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[unique_ptr_factory
#include <fcppt/unique_ptr.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/text.hpp>

//<-
namespace
{
//->
typedef fcppt::unique_ptr<
	int
> unique_int_ptr;

// create a unique_ptr factory
unique_int_ptr
int_ptr_factory()
{
	// make_unique_ptr is a factory function to make a unique_ptr
	// note: an rvalue is returned here
	return
		fcppt::make_unique_ptr<
			int
		>(
			42
		);
}

// make a function that takes a unique_ptr
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
//]


//[unique_ptr_move

#include <fcppt/move.hpp>

unique_int_ptr
test2()
{
	unique_int_ptr ptr(
		fcppt::make_unique_ptr<
			int
		>(
			42
		)
	);

	return
		fcppt::move(
			ptr
		);
}

//]
}

//[unique_ptr_shared_ptr

#include <fcppt/shared_ptr_impl.hpp>

//<-
namespace
{
//->
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
			fcppt::move(
				ptr
			)
		);
}

//]

}

//[unique_ptr_derived

//<-
namespace
{
//->

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
test3()
{
	typedef fcppt::unique_ptr<
		base
	> base_ptr;

	base_ptr foo(
		fcppt::make_unique_ptr<
			dervied
		>()
	);
}
//]

}

int main()
{
	::test();

	::test2();

	::to_shared_ptr(
		::int_ptr_factory()
	);

	::test3();
}
