//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_AS_STRUCT_HPP_INCLUDED
#define FCPPT_PARSE_AS_STRUCT_HPP_INCLUDED

#include <fcppt/parse/convert_impl.hpp>
#include <fcppt/parse/make_convert.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/tuple/as_struct.hpp>
#include <fcppt/tuple/is_object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::parse
{
/**
\brief Creates a parser that converts a tuple into a struct.

\ingroup fcpptparse

If \a Parser returns an <code>fcppt::tuple::object<T_1,...,T_n>{t_1,...,t_n}</code>,
then <code>Result{t_1,...,t_n}</code> is returned.
This implies that <code>Result</code> must be constructible from <code>T_1,...,T_n</code>.

\tparam Parser A parser whose result is an <code>fcppt::tuple::object</code>.
*/
template <typename Result, typename Parser>
fcppt::parse::convert<std::remove_cvref_t<Parser>, Result> as_struct(Parser &&_parser)
  requires(fcppt::tuple::is_object<fcppt::parse::result_of<Parser>>::value)
{
  return fcppt::parse::make_convert(
      std::forward<Parser>(_parser),
      [](fcppt::parse::result_of<Parser> &&_tuple)
      { return fcppt::tuple::as_struct<Result>(std::move(_tuple)); });
}
}

#endif
