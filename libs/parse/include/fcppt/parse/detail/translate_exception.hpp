//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_DETAIL_TRANSLATE_EXCEPTION_HPP_INCLUDED
#define FCPPT_PARSE_DETAIL_TRANSLATE_EXCEPTION_HPP_INCLUDED

#include <fcppt/copy.hpp>
#include <fcppt/either/make_failure.hpp>
#include <fcppt/either/object_impl.hpp>
#include <fcppt/parse/parse_stream_error.hpp>
#include <fcppt/parse/detail/exception.hpp>

namespace fcppt::parse::detail
{

template <typename Result, typename Ch>
[[nodiscard]] inline fcppt::either::object<fcppt::parse::parse_stream_error<Ch>, Result>
translate_exception(fcppt::parse::detail::exception<Ch> const &_error)
{
  return fcppt::either::make_failure<Result>(
      fcppt::parse::parse_stream_error<Ch>{fcppt::copy(_error.what())});
}

}

#endif
