//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONFIG_EXTERNAL_BEGIN_HPP_INCLUDED
#define FCPPT_CONFIG_EXTERNAL_BEGIN_HPP_INCLUDED

#if defined(FCPPT_CONFIG_INSIDE_EXTERNAL)
#error "Missing #include <fcppt/config/external_end.hpp>"
#endif

#include <fcppt/config/compiler.hpp>
#include <fcppt/config/warnings.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
FCPPT_PP_PUSH_WARNING

#if defined(FCPPT_CONFIG_MSVC_COMPILER)

#include <fcppt/preprocessor/disable_vc_warning.hpp>
FCPPT_PP_DISABLE_VC_WARNING(4061) // enum not handled in switch
FCPPT_PP_DISABLE_VC_WARNING(4100) // unreferenced formal parameter
FCPPT_PP_DISABLE_VC_WARNING(4127) // conditional expression is constant
FCPPT_PP_DISABLE_VC_WARNING(4146) // unary minus operator applied to unsigned type, result still unsigned
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
FCPPT_PP_DISABLE_VC_WARNING(4324) // structure was padded due to __declspec(align())
FCPPT_PP_DISABLE_VC_WARNING(4347) // behaviour change
FCPPT_PP_DISABLE_VC_WARNING(4365) // signed/unsigned mismatch in action
FCPPT_PP_DISABLE_VC_WARNING(4510) // default constructor could not be generated
FCPPT_PP_DISABLE_VC_WARNING(4512) // assignment operator could not be generated
FCPPT_PP_DISABLE_VC_WARNING(4548) // expression before comma has no effect
FCPPT_PP_DISABLE_VC_WARNING(4555) // expression has no effect
FCPPT_PP_DISABLE_VC_WARNING(4610) // T can never be instantiated because of private ctors
FCPPT_PP_DISABLE_VC_WARNING(4619) // invalid pragma warning
FCPPT_PP_DISABLE_VC_WARNING(4625) // copy constructor could not be generated because of a base class
FCPPT_PP_DISABLE_VC_WARNING(4626) // assignment operator could not be generated because of a base class
FCPPT_PP_DISABLE_VC_WARNING(4640) // local static object
FCPPT_PP_DISABLE_VC_WARNING(4668) // #if with an undefined macro
FCPPT_PP_DISABLE_VC_WARNING(4702) // unreachable code
FCPPT_PP_DISABLE_VC_WARNING(4986) // unmatching exception specification
FCPPT_PP_DISABLE_VC_WARNING(4987) // non standard throw(...)

#elif defined(FCPPT_CONFIG_GCC_COMPILER)

#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#if defined(FCPPT_CONFIG_CLANG_COMPILER)
FCPPT_PP_DISABLE_GCC_WARNING(-Wnewline-eof)
FCPPT_PP_DISABLE_GCC_WARNING(-Wtautological-compare)
#endif
#if defined(FCPPT_CONFIG_HAVE_DELETE_NON_VIRTUAL_DTOR_WARNING)
	FCPPT_PP_DISABLE_GCC_WARNING(-Wdelete-non-virtual-dtor)
#endif
#if defined(FCPPT_CONFIG_HAVE_DOUBLE_PROMOTION_WARNING)
	FCPPT_PP_DISABLE_GCC_WARNING(-Wdouble-promotion)
#endif
#if defined(FCPPT_CONFIG_HAVE_EXTRA_SEMI_WARNING)
	FCPPT_PP_DISABLE_GCC_WARNING(-Wextra-semi)
#endif
#if defined(FCPPT_CONFIG_HAVE_IMPLICIT_FALLTHROUGH_WARNING)
	FCPPT_PP_DISABLE_GCC_WARNING(-Wimplicit-fallthrough)
#endif
#if defined(FCPPT_CONFIG_HAVE_LOGICAL_OP_WARNING)
	FCPPT_PP_DISABLE_GCC_WARNING(-Wlogical-op)
#endif
#if defined(FCPPT_CONFIG_HAVE_MAYBE_UNINITIALIZED_WARNING)
	FCPPT_PP_DISABLE_GCC_WARNING(-Wmaybe-uninitialized)
#endif
#if defined(FCPPT_CONFIG_HAVE_MISSING_DECLARATIONS_WARNING)
	FCPPT_PP_DISABLE_GCC_WARNING(-Wmissing-declarations)
#endif
#if defined(FCPPT_CONFIG_HAVE_SIGN_CONVERSION_WARNING)
	FCPPT_PP_DISABLE_GCC_WARNING(-Wsign-conversion)
#endif
#if defined(FCPPT_CONFIG_HAVE_UNNEEDED_MEMBER_FUNCTION_WARNING)
	FCPPT_PP_DISABLE_GCC_WARNING(-Wunneeded-member-function)
#endif
#if defined(FCPPT_CONFIG_HAVE_UNUSED_MEMBER_FUNCTION_WARNING)
	FCPPT_PP_DISABLE_GCC_WARNING(-Wunused-member-function)
#endif
#if defined(FCPPT_CONFIG_HAVE_ZERO_AS_NULL_POINTER_CONSTANT_WARNING)
	FCPPT_PP_DISABLE_GCC_WARNING(-Wzero-as-null-pointer-constant)
#endif
FCPPT_PP_DISABLE_GCC_WARNING(-Wattributes)
FCPPT_PP_DISABLE_GCC_WARNING(-Wcast-align)
FCPPT_PP_DISABLE_GCC_WARNING(-Wcast-qual)
FCPPT_PP_DISABLE_GCC_WARNING(-Wconversion)
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)
FCPPT_PP_DISABLE_GCC_WARNING(-Wfloat-equal)
FCPPT_PP_DISABLE_GCC_WARNING(-Wignored-qualifiers)
FCPPT_PP_DISABLE_GCC_WARNING(-Wnon-virtual-dtor)
FCPPT_PP_DISABLE_GCC_WARNING(-Wold-style-cast)
FCPPT_PP_DISABLE_GCC_WARNING(-Woverloaded-virtual)
FCPPT_PP_DISABLE_GCC_WARNING(-Wredundant-decls)
FCPPT_PP_DISABLE_GCC_WARNING(-Wshadow)
FCPPT_PP_DISABLE_GCC_WARNING(-Wstrict-aliasing)
FCPPT_PP_DISABLE_GCC_WARNING(-Wtype-limits)
// This currently doesn't silence -Wundef warnings
FCPPT_PP_DISABLE_GCC_WARNING(-Wundef)
FCPPT_PP_DISABLE_GCC_WARNING(-Wuninitialized)
FCPPT_PP_DISABLE_GCC_WARNING(-Wunused-parameter)
FCPPT_PP_DISABLE_GCC_WARNING(-Wunused-variable)

#elif defined(FCPPT_CONFIG_ICC_COMPILER)

#include <fcppt/preprocessor/disable_icc_warning.hpp>
FCPPT_PP_DISABLE_ICC_WARNING(193) // zero used for undefined preprocessor identifier
FCPPT_PP_DISABLE_ICC_WARNING(279) // controlling expression is constant
FCPPT_PP_DISABLE_ICC_WARNING(593) // variable set but never used
FCPPT_PP_DISABLE_ICC_WARNING(2304) // non-explicit constructor with single argument
FCPPT_PP_DISABLE_ICC_WARNING(2415) // unused variable with static storage

#endif

#define FCPPT_CONFIG_INSIDE_EXTERNAL

#endif

#undef FCPPT_CONFIG_EXTERNAL_BEGIN_HPP_INCLUDED
