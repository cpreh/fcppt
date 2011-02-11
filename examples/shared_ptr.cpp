//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/preprocessor/disable_vc_warning.hpp>
FCPPT_PP_DISABLE_VC_WARNING(4702)

//[sharedptr_normal
#include <fcppt/shared_ptr_impl.hpp>

namespace
{

typedef fcppt::shared_ptr<
	int
> int_ptr;

int_ptr
factory()
{
	return
		int_ptr(
			new int(42)
		);
}

}

//]

//[sharedptr_deleter

#include <fcppt/c_deleter.hpp>
#include <stdexcept>
#include <cstdlib>

namespace
{

typedef fcppt::shared_ptr<
	void,
	fcppt::c_deleter
> void_c_ptr;

void
test_c_deleter()
{
	void_c_ptr ptr(
		std::malloc(
			100
		)
	);

	// calls std::free
}

}

//]

namespace
{

//[sharedptr_wrong
void
take_pointer(
	int_ptr,
	bool
)
{
	//
}

bool
throw_something()
{
	throw std::runtime_error("test");
}

void
wrong()
{
	// The order in which function arguments and their sub expressions are evaluated is unspecified.
	// So it might be possible that they are evaluated as follows:
	// a) new int(100)
	// b) throw_something()
	// c) int_ptr(...) is never reached and we have a leak
	take_pointer(
		int_ptr(
			new int (100)
		),
		throw_something()
	);
}
//]
}

//[sharedptr_make

#include <fcppt/make_shared_ptr.hpp>

namespace
{

void
right()
{
	take_pointer(
		fcppt::make_shared_ptr<
			int
		>(
			100
		),
		throw_something()
	);
}

}
//]

//[sharedptr_cast

#include <fcppt/static_pointer_cast.hpp>

namespace
{

struct base
{};

struct derived
:
base
{};

void
cast()
{
	typedef fcppt::shared_ptr<
		base
	> base_ptr;

	base_ptr ptr(
		new derived()
	);

	typedef fcppt::shared_ptr<
		derived
	> derived_ptr;

	derived_ptr dptr(
		fcppt::static_pointer_cast<
			derived
		>(
			ptr
		)
	);
}

}
//]

int main()
{
	factory();

	test_c_deleter();

	wrong();

	right();

	cast();
}
