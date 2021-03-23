//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_DETAIL_CHAR_LITERAL_HPP_INCLUDED
#define FCPPT_DETAIL_CHAR_LITERAL_HPP_INCLUDED

#include <fcppt/detail/char_types.hpp>
#include <fcppt/metal/as_tuple.hpp>
#include <fcppt/metal/index_of.hpp>
#include <fcppt/tuple/get.hpp>

namespace fcppt::detail
{
template <typename Type>
inline Type char_literal(fcppt::metal::as_tuple<fcppt::detail::char_types> const &_args)
{
  return fcppt::tuple::get<fcppt::metal::index_of<fcppt::detail::char_types, Type>::value>(_args);
}
}

#endif
