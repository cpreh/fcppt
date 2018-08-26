//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONFIG_EXTERNAL_BEGIN_HPP_INCLUDED
#define FCPPT_CONFIG_EXTERNAL_BEGIN_HPP_INCLUDED

#include <fcppt/detail/check_cpp.hpp>

#include <fcppt/config/external_begin.h>

#if defined(FCPPT_CONFIG_INSIDE_EXTERNAL_HPP)
#error "Missing #include <fcppt/config/external_end.hpp>"
#endif

#include <fcppt/config/compiler.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
FCPPT_PP_PUSH_WARNING

#if defined(FCPPT_CONFIG_MSVC_COMPILER)

#include <fcppt/preprocessor/disable_vc_warning.hpp>
FCPPT_PP_DISABLE_VC_WARNING(4005) // macro redefinition
FCPPT_PP_DISABLE_VC_WARNING(4061) // enum not handled in switch
FCPPT_PP_DISABLE_VC_WARNING(4100) // unreferenced formal parameter
FCPPT_PP_DISABLE_VC_WARNING(4127) // conditional expression is constant
FCPPT_PP_DISABLE_VC_WARNING(4146) // unary minus operator applied to unsigned type, result still unsigned
FCPPT_PP_DISABLE_VC_WARNING(4180) // qualifier applied to function type
FCPPT_PP_DISABLE_VC_WARNING(4189) // local variable is initialized but not referenced
FCPPT_PP_DISABLE_VC_WARNING(4191) // unsafe type cast
FCPPT_PP_DISABLE_VC_WARNING(4242) // loss of data
FCPPT_PP_DISABLE_VC_WARNING(4244) // conversion, possible loss of data
FCPPT_PP_DISABLE_VC_WARNING(4245) // signed/unsigned mismatch in initialization
FCPPT_PP_DISABLE_VC_WARNING(4263) // member function does not override any base class virtual member function
FCPPT_PP_DISABLE_VC_WARNING(4264) // no override available for virtual member function from base
FCPPT_PP_DISABLE_VC_WARNING(4265) // destructor not virtual
FCPPT_PP_DISABLE_VC_WARNING(4266) // no override available for virtual member function from base
FCPPT_PP_DISABLE_VC_WARNING(4302) // type cast truncation
FCPPT_PP_DISABLE_VC_WARNING(4307) // integral constant overflow
FCPPT_PP_DISABLE_VC_WARNING(4309) // truncation of constant value
FCPPT_PP_DISABLE_VC_WARNING(4324) // structure was padded due to __declspec(align())
FCPPT_PP_DISABLE_VC_WARNING(4348) // redefinition of default parameter
FCPPT_PP_DISABLE_VC_WARNING(4365) // signed/unsigned mismatch in action
FCPPT_PP_DISABLE_VC_WARNING(4459) // declaration hides global declaration
FCPPT_PP_DISABLE_VC_WARNING(4510) // default constructor could not be generated
FCPPT_PP_DISABLE_VC_WARNING(4512) // assignment operator could not be generated
FCPPT_PP_DISABLE_VC_WARNING(4548) // expression before comma has no effect
FCPPT_PP_DISABLE_VC_WARNING(4555) // expression has no effect
FCPPT_PP_DISABLE_VC_WARNING(4610) // T can never be instantiated because of private ctors
FCPPT_PP_DISABLE_VC_WARNING(4619) // invalid pragma warning
FCPPT_PP_DISABLE_VC_WARNING(4623) // default constructor implicitly deleted
FCPPT_PP_DISABLE_VC_WARNING(4625) // copy constructor could not be generated because of a base class
FCPPT_PP_DISABLE_VC_WARNING(4626) // assignment operator could not be generated because of a base class
FCPPT_PP_DISABLE_VC_WARNING(4628) // digraphs not supported
FCPPT_PP_DISABLE_VC_WARNING(4640) // local static object
FCPPT_PP_DISABLE_VC_WARNING(4668) // #if with an undefined macro
FCPPT_PP_DISABLE_VC_WARNING(4702) // unreachable code
FCPPT_PP_DISABLE_VC_WARNING(4819) // unrepresentable characters
FCPPT_PP_DISABLE_VC_WARNING(4913) // user defined binary operator, exists but is not used
FCPPT_PP_DISABLE_VC_WARNING(4986) // unmatching exception specification
FCPPT_PP_DISABLE_VC_WARNING(4987) // non standard throw(...)
FCPPT_PP_DISABLE_VC_WARNING(5026) // move constructor could not be generated
FCPPT_PP_DISABLE_VC_WARNING(5027) // move assignment operator could not be generated

#include <fcppt/config/msvc_version_at_least.hpp>

#if FCPPT_CONFIG_MSVC_VERSION_AT_LEAST(1910)
FCPPT_PP_DISABLE_VC_WARNING(4774) // format string expected
#endif

#elif defined(FCPPT_CONFIG_GCC_COMPILER)

#include <fcppt/preprocessor/disable_gcc_warning.hpp>

#if defined(FCPPT_CONFIG_CLANG_COMPILER)

FCPPT_PP_DISABLE_GCC_WARNING(-Wmismatched-tags)
FCPPT_PP_DISABLE_GCC_WARNING(-Wunneeded-member-function)
FCPPT_PP_DISABLE_GCC_WARNING(-Wunused-member-function)

#include <fcppt/config/clang_version_at_least.hpp>

#if FCPPT_CONFIG_CLANG_VERSION_AT_LEAST(3, 6)
FCPPT_PP_DISABLE_GCC_WARNING(-Winconsistent-missing-override)
#endif

#if FCPPT_CONFIG_CLANG_VERSION_AT_LEAST(3, 9)
FCPPT_PP_DISABLE_GCC_WARNING(-Wundefined-var-template)
#endif

#else

FCPPT_PP_DISABLE_GCC_WARNING(-Wliteral-suffix)
FCPPT_PP_DISABLE_GCC_WARNING(-Wsuggest-override)
FCPPT_PP_DISABLE_GCC_WARNING(-Wzero-as-null-pointer-constant)

#include <fcppt/config/gcc_version_at_least.hpp>

#if FCPPT_CONFIG_GCC_VERSION_AT_LEAST(6, 0)
FCPPT_PP_DISABLE_GCC_WARNING(-Wnull-dereference)
#endif

#if FCPPT_CONFIG_GCC_VERSION_AT_LEAST(8, 0)
FCPPT_PP_DISABLE_GCC_WARNING(-Wclass-memaccess)
#endif

#endif

FCPPT_PP_DISABLE_GCC_WARNING(-Wdelete-non-virtual-dtor)
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)
FCPPT_PP_DISABLE_GCC_WARNING(-Wnon-virtual-dtor)
FCPPT_PP_DISABLE_GCC_WARNING(-Wold-style-cast)
FCPPT_PP_DISABLE_GCC_WARNING(-Woverloaded-virtual)
FCPPT_PP_DISABLE_GCC_WARNING(-Wsign-promo)

#endif

#define FCPPT_CONFIG_INSIDE_EXTERNAL_HPP

#endif

#undef FCPPT_CONFIG_EXTERNAL_BEGIN_HPP_INCLUDED
