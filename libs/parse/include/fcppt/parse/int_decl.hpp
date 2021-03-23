//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_INT_DECL_HPP_INCLUDED
#define FCPPT_PARSE_INT_DECL_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/int_fwd.hpp>
#include <fcppt/parse/result_fwd.hpp>
#include <fcppt/parse/tag.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace parse
{
/**
\brief Parses signed integers.
\ingroup fcpptparse

A signed integer string optionally starts with the symbol '-'.
It is then followed by a nonempty sequence of #fcppt::parse::digits.
The string is converted into a signed integer using #fcppt::extract_from_string.

\tparam Type Must be a signed integer type.
*/
template <typename Type>
class int_ : private fcppt::parse::tag
{
public:
  static_assert(std::is_integral_v<Type>, "Type must be an integral type");

  static_assert(std::is_signed_v<Type>, "Type must be signed");

  int_();

  using result_type = Type;

  template <typename Ch, typename Skipper>
  [[nodiscard]] fcppt::parse::result<Ch, result_type>
  parse(fcppt::reference<fcppt::parse::basic_stream<Ch>>, Skipper const &) const;
};

}
}

#endif
