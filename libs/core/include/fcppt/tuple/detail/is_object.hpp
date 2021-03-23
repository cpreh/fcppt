//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_TUPLE_DETAIL_IS_OBJECT_HPP_INCLUDED
#define FCPPT_TUPLE_DETAIL_IS_OBJECT_HPP_INCLUDED

#include <fcppt/tuple/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::tuple::detail
{
template <typename T>
struct is_object
{
  using type = std::false_type;
};

template <typename... Args>
struct is_object<fcppt::tuple::object<Args...>>
{
  using type = std::true_type;
};
}

#endif
