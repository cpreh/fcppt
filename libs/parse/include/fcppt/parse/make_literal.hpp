//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_MAKE_LITERAL_HPP_INCLUDED
#define FCPPT_PARSE_MAKE_LITERAL_HPP_INCLUDED

#include <fcppt/parse/basic_literal_impl.hpp>

namespace fcppt
{
namespace parse
{
/**
\brief Creates an #fcppt::parse::basic_literal parser.
\ingroup fcpptparse
*/
template <typename Ch>
fcppt::parse::basic_literal<Ch> make_literal(Ch const _ch)
{
  return fcppt::parse::basic_literal<Ch>{_ch};
}

}
}

#endif
