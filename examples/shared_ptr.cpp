//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/preprocessor/disable_vc_warning.hpp>
FCPPT_PP_DISABLE_VC_WARNING(4702)
#include <fcppt/shared_ptr_impl.hpp>
#include <fcppt/text.hpp>
#include <fcppt/io/cout.hpp>

namespace
{

//! [shared_ptr_example]

// Typedef a shared_ptr to in int
typedef fcppt::shared_ptr<
	int
> int_ptr;

// Objects of this class should share ownership of int_ptrs
class owner
{
public:
	explicit
	owner(
		int_ptr _ptr
	)
	:
		ptr_(
			_ptr
		)
	{
	}
private:
	int_ptr ptr_;
};

void
shared_ptr_example()
{
	// Creates a shared_ptr
	int_ptr const ptr(
		new int(42)
	);

	// Copies the ownership to owner1, increasing the shared count to 2
	owner owner1(
		ptr
	);

	// Copies from owner1 to owner2, increasing the shared count to 3
	owner owner2(
		owner1
	);

	// The destruction of owner2, owner1 and ptr will free the int
}

}
//! [shared_ptr_example]

#include <fcppt/c_deleter.hpp>
#include <fcppt/config/external_begin.hpp>
#include <stdexcept>
#include <cstdlib>
#include <fcppt/config/external_end.hpp>

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

namespace
{

//! [shared_ptr_make_shared_wrong]

// Create a function that takes ownership of an int_ptr, but also takes another
// argument.
void
take_pointer(
	int_ptr,
	bool
)
{
	//
}

// This function will be used to provide a bool value for take_pointer, but it
// throws when executed.
bool
throw_something()
{
	throw std::runtime_error("test");
}

void
wrong()
{
	// The order in which function arguments and their sub-expressions are
	// evaluated is unspecified. So it might be possible that they are
	// evaluated as follows:
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
//! [shared_ptr_make_shared_wrong]
}

#include <fcppt/make_shared_ptr.hpp>

namespace
{

//! [shared_ptr_make_shared_right]
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
//! [shared_ptr_make_shared_right]

}

#include <fcppt/dynamic_pointer_cast.hpp>
#include <fcppt/optional/object_impl.hpp>

namespace
{

// ![shared_ptr_cast]
struct base
{
	virtual ~base()
	{
	}
};

struct derived
:
base
{};

void
cast()
{
	typedef
	fcppt::shared_ptr<
		base
	>
	base_ptr;

	base_ptr ptr(
		new derived()
	);

	typedef
	fcppt::shared_ptr<
		derived
	>
	derived_ptr;

	fcppt::optional::object<
		derived_ptr
	> dptr(
		fcppt::dynamic_pointer_cast<
			derived
		>(
			ptr
		)
	);

	if(
		dptr.has_value()
	)
		fcppt::io::cout()
			<< FCPPT_TEXT("ptr points to a derived.\n");
}
// ![shared_ptr_cast]

}

int
main()
{
	shared_ptr_example();

	test_c_deleter();

	wrong();

	right();

	cast();
}
