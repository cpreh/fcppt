//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PREPROCESSOR_PRAGMA_HPP_INCLUDED
#define FCPPT_PREPROCESSOR_PRAGMA_HPP_INCLUDED

#include <fcppt/preprocessor/detail/pragma.hpp>

/**
\brief A macro that expands to a pragma directive

\ingroup fcpptpreprocessor

Expands expr as if <code>\#pragma expr</code> was written. This is useful to
embed pragmas into macro definitions which is normally not possible.

\param expr The pragma expression
*/
#define FCPPT_PP_PRAGMA(\
	expr\
)\
FCPPT_PP_DETAIL_PRAGMA(\
	expr\
)

#endif
