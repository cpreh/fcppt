//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_DEREF_HPP_INCLUDED
#define FCPPT_OPTIONS_DEREF_HPP_INCLUDED

#include <fcppt/deref.hpp>
#include <fcppt/deref_reference.hpp>
#include <fcppt/deref_unique_ptr.hpp>

namespace fcppt
{
namespace options
{
/**
\brief Dereferences a parser.

\ingroup fcpptoptions

Parsers can be stored by copy, by reference or by unique pointer.
*/
template <typename Parser>
inline decltype(auto) deref(Parser const &_parser)
{
  return fcppt::deref(_parser);
}

}
}

#endif
