//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONFIG_EXTERNAL_BEGIN_HPP_INCLUDED
#define FCPPT_CONFIG_EXTERNAL_BEGIN_HPP_INCLUDED

#include <fcppt/detail/check_cpp.hpp> // IWYU pragma: keep

#include <fcppt/config/external_begin.h> // IWYU pragma: keep

#include <fcppt/config/compiler.hpp> // IWYU pragma: keep
#include <fcppt/preprocessor/push_warning.hpp>
FCPPT_PP_PUSH_WARNING

#ifdef FCPPT_CONFIG_MSVC_COMPILER

#include <fcppt/config/msvc_version_at_least.hpp>
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
FCPPT_PP_DISABLE_VC_WARNING(4296) // expression is always false
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
FCPPT_PP_DISABLE_VC_WARNING(4582) // constructor not implicitly called
FCPPT_PP_DISABLE_VC_WARNING(4583) // destructor not implicitly called
FCPPT_PP_DISABLE_VC_WARNING(4610) // T can never be instantiated because of private ctors
FCPPT_PP_DISABLE_VC_WARNING(4619) // invalid pragma warning
FCPPT_PP_DISABLE_VC_WARNING(4623) // default constructor implicitly deleted
FCPPT_PP_DISABLE_VC_WARNING(4625) // copy constructor could not be generated because of a base class
FCPPT_PP_DISABLE_VC_WARNING(4626) // assignment operator could not be generated because of a base class
FCPPT_PP_DISABLE_VC_WARNING(4628) // digraphs not supported
FCPPT_PP_DISABLE_VC_WARNING(4640) // local static object
FCPPT_PP_DISABLE_VC_WARNING(4643) // forward declaration in namespace std
FCPPT_PP_DISABLE_VC_WARNING(4668) // #if with an undefined macro
FCPPT_PP_DISABLE_VC_WARNING(4702) // unreachable code
FCPPT_PP_DISABLE_VC_WARNING(4774) // format string expected
FCPPT_PP_DISABLE_VC_WARNING(4819) // unrepresentable characters
FCPPT_PP_DISABLE_VC_WARNING(4913) // user defined binary operator, exists but is not used
FCPPT_PP_DISABLE_VC_WARNING(4986) // unmatching exception specification
FCPPT_PP_DISABLE_VC_WARNING(4987) // non standard throw(...)
FCPPT_PP_DISABLE_VC_WARNING(5026) // move constructor could not be generated
FCPPT_PP_DISABLE_VC_WARNING(5027) // move assignment operator could not be generated
FCPPT_PP_DISABLE_VC_WARNING(5045) // Spectre mitigation for memory load
#if FCPPT_CONFIG_MSVC_VERSION_AT_LEAST(1925)
FCPPT_PP_DISABLE_VC_WARNING(5204) // Class with virtual functions but without virtual destrutor
#endif
#if FCPPT_CONFIG_MSVC_VERSION_AT_LEAST(1929)
FCPPT_PP_DISABLE_VC_WARNING(5243) // Incomplete class causing ABI violation
#endif
#if FCPPT_CONFIG_MSVC_VERSION_AT_LEAST(1934)
FCPPT_PP_DISABLE_VC_WARNING(5262) // implicit fall-through
FCPPT_PP_DISABLE_VC_WARNING(5264) // 'const' variable is not used
#endif

#elifdef FCPPT_CONFIG_GCC_COMPILER

#include <fcppt/preprocessor/disable_gcc_warning.hpp>

#ifdef FCPPT_CONFIG_CLANG_COMPILER

FCPPT_PP_DISABLE_GCC_WARNING(-Wdeprecated-dynamic-exception-spec)
FCPPT_PP_DISABLE_GCC_WARNING(-Wdisabled-macro-expansion)
FCPPT_PP_DISABLE_GCC_WARNING(-Wduplicate-enum)
FCPPT_PP_DISABLE_GCC_WARNING(-Wexit-time-destructors)
FCPPT_PP_DISABLE_GCC_WARNING(-Wglobal-constructors)
FCPPT_PP_DISABLE_GCC_WARNING(-Winconsistent-missing-override)
FCPPT_PP_DISABLE_GCC_WARNING(-Winconsistent-missing-destructor-override)
FCPPT_PP_DISABLE_GCC_WARNING(-Wmismatched-tags)
FCPPT_PP_DISABLE_GCC_WARNING(-Wmissing-noreturn)
FCPPT_PP_DISABLE_GCC_WARNING(-Wshadow-field)
FCPPT_PP_DISABLE_GCC_WARNING(-Wundefined-func-template)
FCPPT_PP_DISABLE_GCC_WARNING(-Wundefined-var-template)
FCPPT_PP_DISABLE_GCC_WARNING(-Wunneeded-member-function)
FCPPT_PP_DISABLE_GCC_WARNING(-Wunused-member-function)
FCPPT_PP_DISABLE_GCC_WARNING(-Wunused-template)
FCPPT_PP_DISABLE_GCC_WARNING(-Wused-but-marked-unused)
FCPPT_PP_DISABLE_GCC_WARNING(-Wweak-template-vtables)
FCPPT_PP_DISABLE_GCC_WARNING(-Wweak-vtables)

#include <fcppt/config/clang_version_at_least.hpp>

#if FCPPT_CONFIG_CLANG_VERSION_AT_LEAST(11, 0)
FCPPT_PP_DISABLE_GCC_WARNING(-Wsuggest-destructor-override)
FCPPT_PP_DISABLE_GCC_WARNING(-Wsuggest-override)
#endif
#if FCPPT_CONFIG_CLANG_VERSION_AT_LEAST(12, 0)
FCPPT_PP_DISABLE_GCC_WARNING(-Wcompound-token-split-by-space)
#endif

#else

FCPPT_PP_DISABLE_GCC_WARNING(-Wclass-memaccess)
FCPPT_PP_DISABLE_GCC_WARNING(-Wliteral-suffix)
FCPPT_PP_DISABLE_GCC_WARNING(-Wnull-dereference)
FCPPT_PP_DISABLE_GCC_WARNING(-Wsuggest-override)

#include <fcppt/config/gcc_version_at_least.hpp>

#if FCPPT_CONFIG_GCC_VERSION_AT_LEAST(9, 0)
FCPPT_PP_DISABLE_GCC_WARNING(-Wdeprecated-copy)
#endif

#endif

FCPPT_PP_DISABLE_GCC_WARNING(-Wdelete-non-virtual-dtor)
FCPPT_PP_DISABLE_GCC_WARNING(-Wdeprecated)
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)
FCPPT_PP_DISABLE_GCC_WARNING(-Wnon-virtual-dtor)
FCPPT_PP_DISABLE_GCC_WARNING(-Wold-style-cast)
FCPPT_PP_DISABLE_GCC_WARNING(-Woverloaded-virtual)
FCPPT_PP_DISABLE_GCC_WARNING(-Wpadded)
FCPPT_PP_DISABLE_GCC_WARNING(-Wsign-promo)
FCPPT_PP_DISABLE_GCC_WARNING(-Wzero-as-null-pointer-constant)

#endif

#endif

#undef FCPPT_CONFIG_EXTERNAL_BEGIN_HPP_INCLUDED
