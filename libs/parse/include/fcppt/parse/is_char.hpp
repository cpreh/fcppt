//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_IS_CHAR_HPP_INCLUDED
#define FCPPT_PARSE_IS_CHAR_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace parse
{
/**
\brief The allowed char types, currently char and wchar_t.
\ingroup fcpptparse
*/
template <typename Type>
using is_char = std::disjunction<std::is_same<Type, char>, std::is_same<Type, wchar_t>>;

}
}

#endif
