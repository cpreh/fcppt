//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_DETAIL_STREAM_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_DETAIL_STREAM_IMPL_HPP_INCLUDED

#include <fcppt/char_literal.hpp>
#include <fcppt/string_literal.hpp>
#include <fcppt/strong_typedef_arithmetic.hpp>
#include <fcppt/io/get.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/maybe_void.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/parse/basic_stream_impl.hpp>
#include <fcppt/parse/column.hpp>
#include <fcppt/parse/line.hpp>
#include <fcppt/parse/location.hpp>
#include <fcppt/parse/position.hpp>
#include <fcppt/parse/detail/check_bad.hpp>
#include <fcppt/parse/detail/exception.hpp>
#include <fcppt/parse/detail/stream_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <istream>
#include <fcppt/config/external_end.hpp>

template <typename Ch>
fcppt::parse::detail::stream<Ch>::stream(impl_ref const _impl)
    : impl_{_impl}, location_{fcppt::parse::line{1U}, fcppt::parse::column{1U}}
{
}

namespace fcppt::parse::detail
{
template <typename Ch>
stream<Ch>::~stream() = default;
}

template <typename Ch>
fcppt::optional::object<Ch> fcppt::parse::detail::stream<Ch>::get_char()
{
  std::basic_istream<Ch> &std_stream{this->impl_.get()};

  fcppt::parse::detail::check_bad(std_stream);

  fcppt::optional::object<Ch> result{fcppt::io::get(std_stream)};

  fcppt::optional::maybe_void(result, [this](Ch const _value) {
    if (_value == FCPPT_CHAR_LITERAL(Ch, '\n'))
    {
      ++this->location_.line();

      this->location_.column() = fcppt::parse::column{1U};
    }
    else
    {
      ++this->location_.column();
    }
  });

  return result;
}

template <typename Ch>
fcppt::parse::position<Ch> fcppt::parse::detail::stream<Ch>::get_position() const
{
  using pos_type = typename std::basic_istream<Ch>::pos_type;

  std::basic_istream<Ch> &std_stream{this->impl_.get()};

  fcppt::parse::detail::check_bad(std_stream);

  if (std_stream.eof())
  {
    std_stream.clear(); // NOLINT(fuchsia-default-arguments-calls)
  }

  pos_type const pos{std_stream.tellg()};

  if (pos == pos_type{-1})
  {
    throw
        // NOLINTNEXTLINE(hicpp-exception-baseclass)
        fcppt::parse::detail::exception<Ch>{FCPPT_STRING_LITERAL(Ch, "tellg() failed.")};
  }

  return fcppt::parse::position<Ch>{pos, fcppt::optional::make(this->location_)};
}

template <typename Ch>
void fcppt::parse::detail::stream<Ch>::set_position(fcppt::parse::position<Ch> const &_position)
{
  std::basic_istream<Ch> &std_stream{this->impl_.get()};

  fcppt::parse::detail::check_bad(std_stream);

  std_stream.clear(); // NOLINT(fuchsia-default-arguments-calls)

  std_stream.seekg(_position.pos());

  if (std_stream.fail())
  {
    throw
        // NOLINTNEXTLINE(hicpp-exception-baseclass)
        fcppt::parse::detail::exception<Ch>{FCPPT_STRING_LITERAL(Ch, "seekg() failed.")};
  }

  fcppt::optional::maybe_void(
      _position.location(),
      [this](fcppt::parse::location const &_location) { this->location_ = _location; });
}

#endif
