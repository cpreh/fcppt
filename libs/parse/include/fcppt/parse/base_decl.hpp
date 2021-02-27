//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_BASE_DECL_HPP_INCLUDED
#define FCPPT_PARSE_BASE_DECL_HPP_INCLUDED

#include <fcppt/nonmovable.hpp>
#include <fcppt/reference_fwd.hpp>
#include <fcppt/parse/base_fwd.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/result_fwd.hpp>
#include <fcppt/parse/tag.hpp>

namespace fcppt
{
namespace parse
{
/**
\brief Base class for a parser.

\ingroup fcpptparse

The type of a parser usually gets very complicated because it depends on all of its subparsers.
In case we want to declare a parser as a member of a class for example, we want to use a simpler type.
This is achieved by using #fcppt::parse::make_base to create a parser of type base.
The employed technique is also known as type erasure.
*/
template <typename Result, typename Ch, typename Skipper>
class base : private fcppt::parse::tag
{
  FCPPT_NONMOVABLE(base);

protected:
  base();

public:
  virtual ~base();

  using result_type = Result;

  [[nodiscard]] virtual fcppt::parse::result<Ch, result_type>
  parse(fcppt::reference<fcppt::parse::basic_stream<Ch>>, Skipper const &) const = 0;
};

}
}

#endif
