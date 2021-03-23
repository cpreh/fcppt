//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_MATRIX_DETAIL_INIT_STORAGE_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_DETAIL_INIT_STORAGE_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/array/init.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/checked_access.hpp>
#include <fcppt/math/matrix/detail/index_absolute.hpp>
#include <fcppt/config/external_begin.hpp>
#include <tuple>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace math
{
namespace matrix
{
namespace detail
{
template <typename Result, fcppt::math::size_type C, typename... Types>
inline Result init_storage(std::tuple<Types...> &&_values)
{
  return Result{fcppt::array::init<typename Result::array_type>([&_values](auto const _index) {
    using index = fcppt::math::matrix::detail::
        index_absolute<C, fcppt::cast::size<fcppt::math::size_type>(_index())>;

    return fcppt::move_if_rvalue<std::tuple_element_t<index::row(), std::tuple<Types...>>>(
        fcppt::math::detail::checked_access<index::column()>(std::get<index::row()>(_values)));
  })};
}
}
}
}
}

#endif
