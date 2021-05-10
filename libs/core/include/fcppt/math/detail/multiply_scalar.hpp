//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_DETAIL_MULTIPLY_SCALAR_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_MULTIPLY_SCALAR_HPP_INCLUDED

#include <fcppt/tag.hpp>
#include <fcppt/algorithm/loop.hpp>
#include <fcppt/algorithm/loop_break_metal.hpp>
#include <fcppt/math/int_range_count.hpp>
#include <fcppt/math/size_constant.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/storage_size.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>

namespace fcppt
{
namespace math
{
namespace detail
{
template <typename Storage>
void multiply_scalar(Storage &_value, typename Storage::value_type const _mult)
{
  fcppt::algorithm::loop(
      fcppt::math::int_range_count<fcppt::math::detail::storage_size<Storage>::value>{},
      [&_value, _mult]<fcppt::math::size_type Index>(fcppt::tag<fcppt::math::size_constant<Index>>)
      {
        FCPPT_PP_PUSH_WARNING
        FCPPT_PP_DISABLE_VC_WARNING(4709)

        _value[Index] *= _mult;

        FCPPT_PP_POP_WARNING
      });
}

}
}
}

#endif
