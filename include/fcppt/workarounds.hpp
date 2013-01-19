//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_WORKAROUNDS_HPP_INCLUDED
#define FCPPT_WORKAROUNDS_HPP_INCLUDED

#include <fcppt/config/compiler.hpp>

#if defined(FCPPT_CONFIG_MSVC_COMPILER)

#define FCPPT_MSVC_DEPENDANT_TEMPLATE_BUG
#define FCPPT_MSVC_WRONG_TYPE_INFO_BEFORE_BUG

#endif

#endif
