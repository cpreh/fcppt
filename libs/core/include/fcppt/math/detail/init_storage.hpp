//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_DETAIL_INIT_STORAGE_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_INIT_STORAGE_HPP_INCLUDED

#include <fcppt/container/array/init_const.hpp>
#include <fcppt/math/detail/assert_static_storage.hpp>
#include <fcppt/type_traits/value_type.hpp>

namespace fcppt
{
namespace math
{
namespace detail
{
template <typename Result>
inline Result init_storage(fcppt::type_traits::value_type<Result> const &_value)
{
  FCPPT_MATH_DETAIL_ASSERT_STATIC_STORAGE(Result);

  return Result{fcppt::container::array::init_const<typename Result::array_type>(_value)};
}

}
}
}

#endif
