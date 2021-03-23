//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_OPERATORS_NOT_HPP_INCLUDED
#define FCPPT_PARSE_OPERATORS_NOT_HPP_INCLUDED

#include <fcppt/parse/is_valid_argument.hpp>
#include <fcppt/parse/not_impl.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace parse
{
/**
\brief Creates an #fcppt::parse::not_ parser.
\ingroup fcpptparse
*/
template <
    typename Parser,
    typename = std::enable_if_t<fcppt::parse::is_valid_argument<Parser>::value>>
fcppt::parse::not_<fcppt::type_traits::remove_cv_ref_t<Parser>> operator!(Parser &&_parser)
{
  return fcppt::parse::not_<fcppt::type_traits::remove_cv_ref_t<Parser>>{
      std::forward<Parser>(_parser)};
}

}
}

#endif
