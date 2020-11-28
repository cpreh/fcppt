//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_POSITION_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_POSITION_IMPL_HPP_INCLUDED

#include <fcppt/parse/position_decl.hpp>

template <typename Ch>
fcppt::parse::position<Ch>::position(pos_type const _pos, optional_location const _location)
    : pos_{_pos}, location_{_location}
{
}

template <typename Ch>
typename fcppt::parse::position<Ch>::pos_type const &fcppt::parse::position<Ch>::pos() const
{
  return this->pos_;
}

template <typename Ch>
typename fcppt::parse::position<Ch>::optional_location const &
fcppt::parse::position<Ch>::location() const
{
  return this->location_;
}

#endif
