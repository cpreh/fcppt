//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_CONSTRUCT_HPP_INCLUDED
#define FCPPT_PARSE_CONSTRUCT_HPP_INCLUDED

#include <fcppt/parse/convert_impl.hpp>
#include <fcppt/parse/make_convert.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace parse
{
template <typename Result, typename Parser>
fcppt::parse::convert<fcppt::type_traits::remove_cv_ref_t<Parser>, Result>
construct(Parser &&_parser)
{
  return fcppt::parse::make_convert(
      std::forward<Parser>(_parser),
      [](fcppt::parse::result_of<Parser> &&_value) { return Result{std::move(_value)}; });
}

}
}

#endif
