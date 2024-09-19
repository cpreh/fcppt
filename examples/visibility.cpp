//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/preprocessor/disable_clang_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <fcppt/config/external_end.hpp>

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_CLANG_WARNING(-Wunused-macros)

namespace
{

//! [visibility_macros]
#include <fcppt/symbol/export.hpp>
#include <fcppt/symbol/import.hpp>

// MYLIB_EXPORTS should be defined by the build system when the library is
// beign built. If other code includes the library's header, the macro will not
// be defined.
#if defined(MYLIB_EXPORTS)
#define MYLIB_SYMBOL FCPPT_SYMBOL_EXPORT
#else
#define MYLIB_SYMBOL FCPPT_SYMBOL_IMPORT
#endif
//! [visibility_macros]

//![visibility_macros_static]
#include <fcppt/symbol/export.hpp>
#include <fcppt/symbol/import.hpp>

// If MYLIB_STATIC is defined, the library is being built or used as a static
// library. In this case we can't use any special symbols.
#if defined(MYLIB_STATIC)
#define MYLIB_SYMBOL
#elif defined(MYLIB_EXPORTS)
#define MYLIB_SYMBOL FCPPT_SYMBOL_EXPORT
#else
#define MYLIB_SYMBOL FCPPT_SYMBOL_IMPORT
#endif
//![visibility_macros_static]

//![visibility_macros_instantiation_static]
#include <fcppt/symbol/export_class_instantiation.hpp>
#include <fcppt/symbol/export_function_instantiation.hpp>

// Also, we have to leave the macros for explicit instantiations empty, if
// MYLIB_STATIC is defined.
#if defined(MYLIB_STATIC)
#define MYLIB_EXPORT_CLASS_INSTANTIATION
#define MYLIB_EXPORT_FUNCTION_INSTANTIATION
#else
#define MYLIB_EXPORT_CLASS_INSTANTIATION FCPPT_SYMBOL_EXPORT_CLASS_INSTANTIATION
#define MYLIB_EXPORT_FUNCTION_INSTANTIATION FCPPT_SYMBOL_EXPORT_FUNCTION_INSTANTIATION
#endif
//![visibility_macros_instantiation_static]

FCPPT_PP_POP_WARNING

// We really can't use the macros in the example, so undef them
#undef MYLIB_SYMBOL
#define MYLIB_SYMBOL

#if !defined(FCPPT_SYMBOL_EXPORT)
#error "FCPPT_SYMBOL_EXPORT is not defined"
#endif
#undef FCPPT_SYMBOL_EXPORT
#define FCPPT_SYMBOL_EXPORT

//! [visibility_export_function]
namespace mylib
{
// Conditionally export func
MYLIB_SYMBOL
void func();

}
//! [visibility_export_function]

//! [visibility_export_vtable1]
#include <fcppt/symbol/class.hpp>
//! [visibility_export_vtable1]

#if !defined(FCPPT_SYMBOL_CLASS)
#error "FCPPT_SYMBOL_CLASS is not defined"
#endif
#undef FCPPT_SYMBOL_CLASS
#define FCPPT_SYMBOL_CLASS

//! [visibility_export_vtable2]
namespace mylib
{
// Export the vtable of someclass
// NOLINTNEXTLINE(cppcoreguidelines-special-member-functions,hicpp-special-member-functions)
class FCPPT_SYMBOL_CLASS someclass
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

//! [visibility_export_template_function]
namespace mylib
{
template <typename T>
MYLIB_SYMBOL void template_function(T const &);

}
//! [visibility_export_template_function]

//! [visibility_export_template_class]
namespace mylib
{
template <typename T>
class template_class
{
public:
  MYLIB_SYMBOL
  void some_function();
};

}
//! [visibility_export_template_class]

// Define our functions

//! [visibility_define_function]
void mylib::func() {}
//! [visibility_define_function]

mylib::someclass::~someclass() = default;

//! [visibility_define_object]
int const mylib::some_constant = 42;
//! [visibility_define_object]

//! [visibility_define_template_function]

// Define our template function
template <typename T>
void mylib::template_function(T const &)
{
}

// Explicitly instantiate the template function with int and export it
#include <fcppt/symbol/export_function_instantiation.hpp>

template FCPPT_SYMBOL_EXPORT_FUNCTION_INSTANTIATION void mylib::template_function<int>(int const &);
//! [visibility_define_template_function]

//! [visibility_define_template_class]
// Define the member functions of the template class
template <typename T>
void mylib::template_class<T>::some_function()
{
}

// Explicitly instantiate the template class with int and export it
#include <fcppt/symbol/export_class_instantiation.hpp>

template class FCPPT_SYMBOL_EXPORT_CLASS_INSTANTIATION mylib::template_class<int>;
//! [visibility_define_template_class]

}

int main()
{
  mylib::func();
  std::cout << mylib::some_constant << '\n';
  mylib::template_function(0);
  mylib::template_class<int>{}.some_function();
}
