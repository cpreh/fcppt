//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONFIG_EXTERNAL_BEGIN_HPP_INCLUDED
#define FCPPT_CONFIG_EXTERNAL_BEGIN_HPP_INCLUDED

#if defined(FCPPT_CONFIG_INSIDE_EXTERNAL)
#error "Missing #include <fcppt/config/external_end.hpp>"
#endif

#if defined(_MSC_VER)
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4061) // enum not handled in switch
FCPPT_PP_DISABLE_VC_WARNING(4347) // behaviour change
FCPPT_PP_DISABLE_VC_WARNING(4365) // signed/unsigned mismatch
FCPPT_PP_DISABLE_VC_WARNING(4548) // expression before comma has no effect
FCPPT_PP_DISABLE_VC_WARNING(4619) // invalid pragma warning
FCPPT_PP_DISABLE_VC_WARNING(4625) // copy constructor could not be generated because of a base class
FCPPT_PP_DISABLE_VC_WARNING(4626) // assignment operator could not be generated because of a base class
FCPPT_PP_DISABLE_VC_WARNING(4640) // local static object
FCPPT_PP_DISABLE_VC_WARNING(4668) // #if with an undefined macro
FCPPT_PP_DISABLE_VC_WARNING(4986) // unmatching exception specification
#endif

#define FCPPT_CONFIG_INSIDE_EXTERNAL

#endif

#undef FCPPT_CONFIG_EXTERNAL_BEGIN_HPP_INCLUDED
