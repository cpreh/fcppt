//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PREPROCESSOR_STRINGIZE_HPP_INCLUDED
#define FCPPT_PREPROCESSOR_STRINGIZE_HPP_INCLUDED

#include <fcppt/preprocessor/detail/stringize.hpp>

/// Stringizes a macro parameter used with BOOST_PP so that it is compatible with fcppt::string
#define FCPPT_PP_STRINGIZE(s) FCPPT_PP_DETAIL_STRINGIZE(s)

#endif
