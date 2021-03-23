//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_FLOAT_DECL_HPP_INCLUDED
#define FCPPT_PARSE_FLOAT_DECL_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/float_fwd.hpp>
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
\brief Parses floating-point numbers.
\ingroup fcpptparse

A float string optionally starts with the symbol '-'.
It is then followed by a nonempty sequence of #fcppt::parse::digits, followed by a '.' (dot),
followed by another nonempty sequence of #fcppt::parse::digits.
The float string is converted into a floating point number using #fcppt::extract_from_string.

\tparam Type Must be a floating-point type.
*/
template <typename Type>
class float_ : private fcppt::parse::tag
{
public:
  static_assert(std::is_floating_point_v<Type>, "Type must be a floating point type");

  float_();

  using result_type = Type;

  template <typename Ch, typename Skipper>
  [[nodiscard]] fcppt::parse::result<Ch, result_type>
  parse(fcppt::reference<fcppt::parse::basic_stream<Ch>>, Skipper const &) const;
};

}
}

#endif
