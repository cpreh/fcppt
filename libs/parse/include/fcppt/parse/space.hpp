//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_SPACE_HPP_INCLUDED
#define FCPPT_PARSE_SPACE_HPP_INCLUDED

#include <fcppt/parse/char_set.hpp>
#include <fcppt/parse/space_set.hpp>

namespace fcppt
{
namespace parse
{
/**
\brief The char set parser using <code>fcppt::parse::space_set<char></code>.
\ingroup fcpptparse
*/
inline fcppt::parse::char_set space()
{
  return fcppt::parse::char_set{fcppt::parse::space_set<char>()};
}

}
}

#endif
