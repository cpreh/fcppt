//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONFIG_EXTERNAL_BEGIN_HPP_INCLUDED
#define FCPPT_CONFIG_EXTERNAL_BEGIN_HPP_INCLUDED

#if defined(FCPPT_CONFIG_INSIDE_EXTERNAL)
#error "Missing #include <fcppt/config/external_end.hpp>"
#endif

#include <fcppt/config/compiler.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
FCPPT_PP_PUSH_WARNING

#if defined(FCPPT_CONFIG_MSVC_COMPILER)
#include <fcppt/preprocessor/disable_vc_warning.hpp>
FCPPT_PP_DISABLE_VC_WARNING(4061) // enum not handled in switch
FCPPT_PP_DISABLE_VC_WARNING(4127) // conditional expression is constant
FCPPT_PP_DISABLE_VC_WARNING(4242) // loss of data
FCPPT_PP_DISABLE_VC_WARNING(4265) // destructor not virtual
FCPPT_PP_DISABLE_VC_WARNING(4347) // behaviour change
FCPPT_PP_DISABLE_VC_WARNING(4365) // signed/unsigned mismatch
FCPPT_PP_DISABLE_VC_WARNING(4512) // assignment operator could not be generated
FCPPT_PP_DISABLE_VC_WARNING(4548) // expression before comma has no effect
FCPPT_PP_DISABLE_VC_WARNING(4619) // invalid pragma warning
FCPPT_PP_DISABLE_VC_WARNING(4625) // copy constructor could not be generated because of a base class
FCPPT_PP_DISABLE_VC_WARNING(4626) // assignment operator could not be generated because of a base class
FCPPT_PP_DISABLE_VC_WARNING(4640) // local static object
FCPPT_PP_DISABLE_VC_WARNING(4668) // #if with an undefined macro
FCPPT_PP_DISABLE_VC_WARNING(4986) // unmatching exception specification
#elif defined(FCPPT_CONFIG_GCC_COMPILER)
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
FCPPT_PP_DISABLE_GCC_WARNING(-Wconversion)
FCPPT_PP_DISABLE_GCC_WARNING(-Wdouble-promotion)
FCPPT_PP_DISABLE_GCC_WARNING(-Wfloat-equal)
FCPPT_PP_DISABLE_GCC_WARNING(-Wignored-qualifiers)
FCPPT_PP_DISABLE_GCC_WARNING(-Wlogical-op)
FCPPT_PP_DISABLE_GCC_WARNING(-Wmissing-declarations)
FCPPT_PP_DISABLE_GCC_WARNING(-Wnon-virtual-dtor)
FCPPT_PP_DISABLE_GCC_WARNING(-Wold-style-cast)
FCPPT_PP_DISABLE_GCC_WARNING(-Woverloaded-virtual)
FCPPT_PP_DISABLE_GCC_WARNING(-Wredundant-decls)
FCPPT_PP_DISABLE_GCC_WARNING(-Wsign-conversion)
FCPPT_PP_DISABLE_GCC_WARNING(-Wshadow)
FCPPT_PP_DISABLE_GCC_WARNING(-Wstrict-aliasing)
//FCPPT_PP_DISABLE_GCC_WARNING(-Wundef)
FCPPT_PP_DISABLE_GCC_WARNING(-Wunused-parameter)
#endif

#define FCPPT_CONFIG_INSIDE_EXTERNAL

#endif

#undef FCPPT_CONFIG_EXTERNAL_BEGIN_HPP_INCLUDED
