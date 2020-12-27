//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ARRAY_APPLY_HPP_INCLUDED
#define FCPPT_ARRAY_APPLY_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/container/to_reference_type.hpp>
#include <fcppt/array/get.hpp>
#include <fcppt/array/init.hpp>
#include <fcppt/array/is_object.hpp>
#include <fcppt/array/object_impl.hpp>
#include <fcppt/array/size.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::array
{
/**
\brief Applies a function to each tuple of elements of multiple arrays and returns an
array containing the results.

\ingroup fcpptarray

Calls <code>_function(e, e_1, ..., e_n)</code> for every e of \a
_array1 and <code>e_1, ..., e_n</code> of \a _arrays.

\tparam Function Must be a function callable as <code>R (Array1::value_type,
Arrays::value_type...)</code>, where <code>R</code> is the result type.
**/
template <
    typename Function,
    typename Array1,
    typename... Arrays,
    typename = std::enable_if_t<std::conjunction_v<
        fcppt::array::is_object<fcppt::type_traits::remove_cv_ref_t<Array1>>,
        fcppt::array::is_object<fcppt::type_traits::remove_cv_ref_t<Arrays>>...,
        std::is_same<
            fcppt::array::size<fcppt::type_traits::remove_cv_ref_t<Array1>>,
            fcppt::array::size<fcppt::type_traits::remove_cv_ref_t<Arrays>>>...>>>
auto apply(Function const &_function, Array1 &&_array1, Arrays &&..._arrays)
    -> fcppt::array::object<
        decltype(_function(
            fcppt::move_if_rvalue<Array1>(std::declval<fcppt::container::to_reference_type<
                                              std::remove_reference_t<Array1>>>()),
            fcppt::move_if_rvalue<Arrays>(std::declval<fcppt::container::to_reference_type<
                                              std::remove_reference_t<Arrays>>>())...)),
        fcppt::array::size<fcppt::type_traits::remove_cv_ref_t<Array1>>::value>
{
  using result_type = fcppt::array::object<
      fcppt::type_traits::remove_cv_ref_t<decltype(_function(
          fcppt::move_if_rvalue<Array1>(
              std::declval<fcppt::container::to_reference_type<std::remove_reference_t<Array1>>>()),
          fcppt::move_if_rvalue<Arrays>(std::declval<fcppt::container::to_reference_type<
                                            std::remove_reference_t<Arrays>>>())...))>,
      fcppt::array::size<fcppt::type_traits::remove_cv_ref_t<Array1>>::value>;

  return fcppt::array::init<result_type>([&_function, &_array1, &_arrays...](auto const _index) {
    return _function(
        fcppt::move_if_rvalue<Array1>(fcppt::array::get<_index()>(_array1)),
        fcppt::move_if_rvalue<Arrays>(fcppt::array::get<_index()>(_arrays))...);
  });
}
}

#endif
