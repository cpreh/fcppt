//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_DEREF_HPP_INCLUDED
#define FCPPT_PARSE_DEREF_HPP_INCLUDED

#include <fcppt/deref.hpp>
#include <fcppt/deref_reference.hpp> // IWYU pragma: keep
#include <fcppt/deref_unique_ptr.hpp> // IWYU pragma: keep
#include <fcppt/parse/deref_type.hpp>

namespace fcppt::parse
{
/**
\brief Dereferences a parser.
\ingroup fcpptparse

\see fcppt::deref
*/
template <typename Parser>
inline fcppt::parse::deref_type<Parser> const &deref(Parser const &_parser)
{
  return fcppt::deref(_parser);
}

}

#endif
