//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_DETAIL_ARRAY_EQUAL_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_ARRAY_EQUAL_HPP_INCLUDED

#include <fcppt/tag.hpp>
#include <fcppt/algorithm/all_of.hpp>
#include <fcppt/algorithm/loop_break_mpl.hpp>
#include <fcppt/math/int_range_count.hpp>
#include <fcppt/math/size_constant.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/storage_size.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace math
{
namespace detail
{
template <typename T1, typename T2>
inline bool array_equal(T1 const &_v1, T2 const &_v2)
{
  static_assert(std::is_same_v<
                fcppt::math::detail::storage_size<typename T1::storage_type>,
                fcppt::math::detail::storage_size<typename T2::storage_type>>);

  return fcppt::algorithm::all_of(
      fcppt::math::int_range_count<
          fcppt::math::detail::storage_size<typename T1::storage_type>::value>{},
      [&_v1, &_v2]<fcppt::math::size_type Index>(fcppt::tag<fcppt::math::size_constant<Index>>) {
        return _v1.storage()[Index] == _v2.storage()[Index];
      });
}

}
}
}

#endif
