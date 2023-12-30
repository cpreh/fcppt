//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_PARSE_STREAM_ERROR_DECL_HPP_INCLUDED
#define FCPPT_PARSE_PARSE_STREAM_ERROR_DECL_HPP_INCLUDED

#include <fcppt/parse/error_impl.hpp>
#include <fcppt/parse/parse_stream_error_fwd.hpp> // IWYU pragma: keep
#include <fcppt/variant/comparison.hpp> // IWYU pragma: keep
#include <fcppt/variant/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

namespace fcppt::parse
{

template<typename Ch>
class parse_stream_error
{
public:
  // TODO(philipp): We could use something better than basic_string<Ch> here.
  explicit parse_stream_error(fcppt::parse::error<Ch> &&);
  explicit parse_stream_error(std::basic_string<Ch> &&);

  using variant = fcppt::variant::object<fcppt::parse::error<Ch>,std::basic_string<Ch>>;

  [[nodiscard]] variant const &get() const;

  [[nodiscard]] bool operator==(parse_stream_error const &) const = default;
private:
  variant variant_;
};

}

#endif
