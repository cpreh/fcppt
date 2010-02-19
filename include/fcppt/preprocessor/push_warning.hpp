//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PREPROCESSOR_PUSH_WARNING_HPP_INCLUDED
#define FCPPT_PREPROCESSOR_PUSH_WARNING_HPP_INCLUDED

#include <fcppt/preprocessor/pragma.hpp>

/// Push the warning level (only supported on VC++ for now)
#if defined(_MSC_VER)
#define FCPPT_PP_PUSH_WARNING \
FCPPT_PP_PRAGMA(warning(push))
#else
#define FCPPT_PP_PUSH_WARNING
#endif

#endif
