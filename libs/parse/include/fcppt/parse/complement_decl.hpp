//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_COMPLEMENT_DECL_HPP_INCLUDED
#define FCPPT_PARSE_COMPLEMENT_DECL_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/complement_fwd.hpp> // IWYU pragma: keep
#include <fcppt/parse/deref_type.hpp>
#include <fcppt/parse/result_fwd.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/tag.hpp>
#include <fcppt/parse/detail/is_char_set.hpp>

namespace fcppt::parse
{
/**
\brief Builds the complement of a #fcppt::parse::basic_char_set parser.
\ingroup fcpptparse

Given the character set S, let <code>p = fcppt::parse::basic_char_set{S}</code>.
If the next input character is c and c is not in S, then <code>complement{p}</code> returns c.
Otherwise, <code>complement{p}</code> returns an error.

\tparam Parser Must be an #fcppt::parse::basic_char_set
*/
template<typename Parser>
class complement : private fcppt::parse::tag
{
public:
  static_assert(fcppt::parse::detail::is_char_set<fcppt::parse::deref_type<Parser>>::value);

  explicit complement(Parser &&);

  using result_type = fcppt::parse::result_of<Parser>;

  template <typename Ch, typename Skipper>
  [[nodiscard]] fcppt::parse::result<Ch, result_type>
  parse(fcppt::reference<fcppt::parse::basic_stream<Ch>>, Skipper const &) const;

private:
  Parser parser_;
};

}

#endif
