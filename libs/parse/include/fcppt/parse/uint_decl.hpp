//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_UINT_DECL_HPP_INCLUDED
#define FCPPT_PARSE_UINT_DECL_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/result_fwd.hpp>
#include <fcppt/parse/tag.hpp>
#include <fcppt/parse/uint_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace parse
{
/**
\brief Parses unsigned integers.
\ingroup fcpptparse

An unsigned integer string is a nonempty sequence of #fcppt::parse::digits.
The string is converted into an unsigned integer using #fcppt::extract_from_string.

\tparam Type Must be a unsigned integer type.
*/
template <typename Type>
class uint : private fcppt::parse::tag
{
public:
  static_assert(std::is_integral_v<Type>, "Type must be an integral type");

  static_assert(std::is_unsigned_v<Type>, "Type must be signed");

  uint();

  using result_type = Type;

  template <typename Ch, typename Skipper>
  [[nodiscard]] fcppt::parse::result<Ch, result_type>
  parse(fcppt::reference<fcppt::parse::basic_stream<Ch>>, Skipper const &) const;
};

}
}

#endif
