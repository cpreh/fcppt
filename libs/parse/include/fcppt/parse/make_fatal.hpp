//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_MAKE_FATAL_HPP_INCLUDED
#define FCPPT_PARSE_MAKE_FATAL_HPP_INCLUDED

#include <fcppt/parse/fatal_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace parse
{
/**
\brief Creates an #fcppt::parse::fatal parser.
\ingroup fcpptparse
*/
template <typename Parser>
fcppt::parse::fatal<std::remove_cvref_t<Parser>> make_fatal(Parser &&_parser)
{
  return fcppt::parse::fatal<std::remove_cvref_t<Parser>>{
      std::forward<Parser>(_parser)};
}

}
}

#endif
