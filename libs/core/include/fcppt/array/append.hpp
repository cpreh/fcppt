//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ARRAY_APPEND_HPP_INCLUDED
#define FCPPT_ARRAY_APPEND_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/array/get.hpp>
#include <fcppt/array/init.hpp>
#include <fcppt/array/is_object.hpp>
#include <fcppt/array/object_impl.hpp>
#include <fcppt/array/size.hpp>
#include <fcppt/array/value_type.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::array
{
/**
\brief Appends two arrays.

\ingroup fcpptarray

Let <code>_array1 = [x_1, ..., x_n]</code>
and <code>_array2 = [y_1, ..., y_m]</code>.
The result is <code>[x_1, ..., x_n, y_1, ..., y_m]</code>.

Both arrays must have the same value type.
*/
template <
    typename Array1,
    typename Array2,
    typename = std::enable_if_t<std::conjunction_v<
        fcppt::array::is_object<fcppt::type_traits::remove_cv_ref_t<Array1>>,
        fcppt::array::is_object<fcppt::type_traits::remove_cv_ref_t<Array2>>,
        std::is_same<
            fcppt::array::value_type<fcppt::type_traits::remove_cv_ref_t<Array1>>,
            fcppt::array::value_type<fcppt::type_traits::remove_cv_ref_t<Array2>>>>>>
fcppt::array::object<
    fcppt::array::value_type<fcppt::type_traits::remove_cv_ref_t<Array1>>,
    fcppt::array::size<fcppt::type_traits::remove_cv_ref_t<Array1>>::value +
        fcppt::array::size<fcppt::type_traits::remove_cv_ref_t<Array2>>::value>
append(Array1 &&_array1, Array2 &&_array2)
{
  using array1 = fcppt::type_traits::remove_cv_ref_t<Array1>;

  using array2 = fcppt::type_traits::remove_cv_ref_t<Array2>;

  using element_type = fcppt::array::value_type<array1>;

  using array1_size = fcppt::array::size<Array1>;

  return fcppt::array::init<
      fcppt::array::object<element_type, array1_size::value + fcppt::array::size<array2>::value>>(
      [&_array1, &_array2](auto const _index) {
        if constexpr (_index() < array1_size::value)
        {
          return fcppt::move_if_rvalue<Array1>(fcppt::array::get<_index()>(_array1));
        }
        else
        {
          return fcppt::move_if_rvalue<Array2>(
              fcppt::array::get<_index() - array1_size::value>(_array2));
        }
      });
}
}

#endif
