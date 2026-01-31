//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_PARSE_STREAM_ERROR_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_PARSE_STREAM_ERROR_IMPL_HPP_INCLUDED

#include <fcppt/parse/error_impl.hpp>
#include <fcppt/parse/parse_stream_error_decl.hpp> // IWYU pragma: export
#include <fcppt/parse/stream_error.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

template<typename Ch>
fcppt::parse::parse_stream_error<Ch>::parse_stream_error(fcppt::parse::error<Ch> &&_error)
: variant_{std::move(_error)}
{
}

template<typename Ch>
fcppt::parse::parse_stream_error<Ch>::parse_stream_error(fcppt::parse::stream_error const _error)
: variant_{_error}
{
}

template <typename Ch>
typename fcppt::parse::parse_stream_error<Ch>::variant const &
fcppt::parse::parse_stream_error<Ch>::get() const
{
  return this->variant_;
}

#endif
