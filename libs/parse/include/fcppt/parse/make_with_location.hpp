//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_MAKE_WITH_LOCATION_HPP_INCLUDED
#define FCPPT_PARSE_MAKE_WITH_LOCATION_HPP_INCLUDED

#include <fcppt/parse/with_location_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::parse
{
/**
\brief Creates an #fcppt::parse::with_location parser.
\ingroup fcpptparse
*/
template <typename Parser>
fcppt::parse::with_location<std::remove_cvref_t<Parser>>
make_with_location(Parser &&_parser)
{
  return fcppt::parse::with_location<std::remove_cvref_t<Parser>>{
      std::forward<Parser>(_parser)};
}

}

#endif
