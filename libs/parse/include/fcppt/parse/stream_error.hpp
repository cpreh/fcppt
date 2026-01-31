//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_STREAM_ERROR_HPP_INCLUDED
#define FCPPT_PARSE_STREAM_ERROR_HPP_INCLUDED

#include <fcppt/parse/stream_error_fwd.hpp> // IWYU pragma: keep
#include <fcppt/config/external_begin.hpp>
#include <cstdint>
#include <fcppt/config/external_end.hpp>

namespace fcppt::parse
{
enum class stream_error : std::uint8_t
{
  tellg_failed,
  seekg_failed,
  bad_stream
};
}

#endif
