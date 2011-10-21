//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[visibility
#include <fcppt/class_symbol.hpp>
#include <fcppt/export_symbol.hpp>
#include <fcppt/import_symbol.hpp>


// MYLIB_EXPORTS should be defined by the build system
// when the library is built.
// If other code includes the library's header,
// the macro will not be defined.
#ifdef MYLIB_EXPORTS
#define MYLIB_SYMBOL FCPPT_EXPORT_SYMBOL
#else
#define MYLIB_SYMBOL FCPPT_IMPORT_SYMBOL
#endif

//<-
// we really can't use the macros in the example,
// so undef them, but put this inside an exclusion section,
// so it is not shown
#undef MYLIB_SYMBOL
#define MYLIB_SYMBOL
#undef FCPPT_CLASS_SYMBOL
#define FCPPT_CLASS_SYMBOL
//->

namespace mylib
{

// conditionally export f
MYLIB_SYMBOL
void
f();

// make sure the vtable of someclass is exported
class FCPPT_CLASS_SYMBOL someclass
{
public:
	MYLIB_SYMBOL
	virtual ~someclass();
};

}

// define our functions

void
mylib::f()
{
}

mylib::someclass::~someclass()
{}

//]

int main()
{}
