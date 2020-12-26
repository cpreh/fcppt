//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ARRAY_DETAIL_IS_OBJECT_HPP_INCLUDED
#define FCPPT_ARRAY_DETAIL_IS_OBJECT_HPP_INCLUDED

#include <fcppt/array/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::array::detail
{
template <typename T>
struct is_object
{
  using type = std::false_type;
};

template <typename T, std::size_t Size>
struct is_object<fcppt::array::object<T, Size>>
{
  using type = std::true_type;
};
}

#endif
