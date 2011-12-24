//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//! [visibility_macros]
#include <fcppt/export_symbol.hpp>
#include <fcppt/import_symbol.hpp>

// MYLIB_EXPORTS should be defined by the build system when the library is
// begin built. If other code includes the library's header, the macro will not
// be defined.
#if defined(MYLIB_EXPORTS)
#define MYLIB_SYMBOL FCPPT_EXPORT_SYMBOL
#else
#define MYLIB_SYMBOL FCPPT_IMPORT_SYMBOL
#endif
//! [visibility_macros]

// We really can't use the macros in the example, so undef them
#undef MYLIB_SYMBOL
#define MYLIB_SYMBOL
#undef FCPPT_EXPORT_SYMBOL
#define FCPPT_EXPORT_SYMBOL

//! [visibility_export_function]
namespace mylib
{

// Conditionally export func
MYLIB_SYMBOL
void
func();

}
//! [visibility_export_function]

//! [visibility_export_vtable1]
#include <fcppt/class_symbol.hpp>
//! [visibility_export_vtable1]

#undef FCPPT_CLASS_SYMBOL
#define FCPPT_CLASS_SYMBOL

//! [visibility_export_vtable2]
namespace mylib
{
// Export the vtable of someclass
class FCPPT_CLASS_SYMBOL someclass
{
public:
	// Also export its destructor
	MYLIB_SYMBOL
	virtual ~someclass();
};

}
//! [visibility_export_vtable2]

//! [visibility_export_object]
namespace mylib
{

MYLIB_SYMBOL
extern const int some_constant;

}
//! [visibility_export_object]

//! [visibility_export_template]
namespace mylib
{

template<
	typename T
>
MYLIB_SYMBOL
void
template_function(
	T const &
);

}
//! [visibility_export_template]

// define our functions

//! [visibility_define_function]
void
mylib::func()
{
}
//! [visibility_define_function]

mylib::someclass::~someclass()
{}

//! [visibility_define_object]
int const mylib::some_constant = 42;
//! [visibility_define_object]

//! [visibility_define_template]

// Define our template function
template<
	typename T
>
void
mylib::template_function(
	T const &
)
{
}

// Explicitly instantiate the template with int and export it
FCPPT_EXPORT_SYMBOL
template
void
mylib::template_function<
	int
>(
	int const &
);
//! [visibility_define_template]

int main()
{}
