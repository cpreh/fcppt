//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_BLANK_HPP_INCLUDED
#define FCPPT_PARSE_BLANK_HPP_INCLUDED

#include <fcppt/parse/blank_set.hpp>
#include <fcppt/parse/char_set.hpp>

namespace fcppt::parse
{

/**
\brief Parser that parses blank characters.
\ingroup fcpptparse
*/
inline fcppt::parse::char_set blank()
{
  return fcppt::parse::char_set{fcppt::parse::blank_set<char>()};
}

}

#endif
