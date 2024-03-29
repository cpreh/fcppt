//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_BASIC_CHAR_SET_CONTAINER_HPP_INCLUDED
#define FCPPT_PARSE_BASIC_CHAR_SET_CONTAINER_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <unordered_set>
#include <fcppt/config/external_end.hpp>

namespace fcppt::parse
{
/**
\brief The character set type.

\ingroup fcpptparse
*/
template <typename Ch>
using basic_char_set_container = std::unordered_set<Ch>;

}

#endif
