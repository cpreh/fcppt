//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_DETAIL_STRING_LITERAL_HPP_INCLUDED
#define FCPPT_DETAIL_STRING_LITERAL_HPP_INCLUDED

#include <fcppt/detail/string_types.hpp>
#include <fcppt/metal/as_tuple.hpp>
#include <fcppt/config/external_begin.hpp>
#include <tuple>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace detail
{
template <typename Type>
inline Type const *string_literal(fcppt::metal::as_tuple<fcppt::detail::string_types> const &_args)
{
  return std::get<Type const *>(_args);
}

}
}

#endif
