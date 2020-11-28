//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_POSITION_DECL_HPP_INCLUDED
#define FCPPT_PARSE_POSITION_DECL_HPP_INCLUDED

#include <fcppt/optional/object_impl.hpp>
#include <fcppt/parse/location.hpp>
#include <fcppt/parse/position_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <istream>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace parse
{
template <typename Ch>
class position
{
public:
  using pos_type = typename std::basic_istream<Ch>::pos_type;

  using optional_location = fcppt::optional::object<fcppt::parse::location>;

  position(pos_type, optional_location);

  [[nodiscard]] pos_type const &pos() const;

  [[nodiscard]] optional_location const &location() const;

private:
  pos_type pos_;

  optional_location location_;
};

}
}

#endif
