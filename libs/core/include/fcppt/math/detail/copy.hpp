//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_DETAIL_COPY_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_COPY_HPP_INCLUDED

#include <fcppt/array/init.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/assert_static_storage.hpp>
#include <fcppt/math/detail/linear_access.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace math
{
namespace detail
{
template <typename Result, typename Arg>
inline Result copy(Arg const &_arg)
{
  FCPPT_MATH_DETAIL_ASSERT_STATIC_STORAGE(Result);

  return Result{fcppt::array::init<typename Result::array_type>(
      [&_arg]<std::size_t Index>(std::integral_constant<std::size_t,Index>)
      {
        return fcppt::math::detail::linear_access<fcppt::cast::size<fcppt::math::size_type>(Index)>(
            _arg.storage());
      })};
}

}
}
}

#endif
