//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_ARRAY_APPLY_HPP_INCLUDED
#define FCPPT_CONTAINER_ARRAY_APPLY_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/use.hpp>
#include <fcppt/container/to_reference_type.hpp>
#include <fcppt/container/array/init.hpp>
#include <fcppt/container/array/size.hpp>
#include <fcppt/type_traits/is_std_array.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <array>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace container
{
namespace array
{
/**
\brief Applies a function to each tuple of elements of multiple arrays and returns an
array containing the results.

\ingroup fcpptcontainerarray

Calls <code>_function(e, e_1, ..., e_n)</code> for every e of \a
_array1 and <code>e_1, ..., e_n</code> of \a _arrays.

\tparam Array1 Must be a <code>std::array</code>.

\tparam Arrays Must be <code>std::array</code>s.

\tparam Function Must be a function callable as <code>R (Array1::value_type,
Arrays::value_type...)</code>, where <code>R</code> is the result type.
**/
template <typename Function, typename Array1, typename... Arrays>
auto apply(Function const &_function, Array1 &&_array1, Arrays &&..._arrays) -> std::array<
    decltype(_function(
        fcppt::move_if_rvalue<Array1>(
            std::declval<fcppt::container::to_reference_type<std::remove_reference_t<Array1>>>()),
        fcppt::move_if_rvalue<Arrays>(std::declval<fcppt::container::to_reference_type<
                                          std::remove_reference_t<Arrays>>>())...)),
    fcppt::container::array::size<fcppt::type_traits::remove_cv_ref_t<Array1>>::value>
{
  using source1 = fcppt::type_traits::remove_cv_ref_t<Array1>;

  using sources = ::metal::list<fcppt::type_traits::remove_cv_ref_t<Arrays>...>;

  static_assert(fcppt::type_traits::is_std_array<source1>::value, "Source1 must be a std::array");

  static_assert(
      ::metal::all_of<sources, ::metal::trait<fcppt::type_traits::is_std_array>>::value,
      "Arrays must all be std::arrays");

  static_assert(
      ::metal::all_of<
          sources,
          ::metal::bind<
              ::metal::trait<std::is_same>,
              ::metal::bind<::metal::lambda<fcppt::container::array::size>, ::metal::_1>,
              ::metal::always<fcppt::container::array::size<source1>>>>::value,
      "All arrays must have the same number of elements");

  using result_type = std::array<
      fcppt::type_traits::remove_cv_ref_t<decltype(_function(
          fcppt::move_if_rvalue<Array1>(
              std::declval<fcppt::container::to_reference_type<std::remove_reference_t<Array1>>>()),
          fcppt::move_if_rvalue<Arrays>(std::declval<fcppt::container::to_reference_type<
                                            std::remove_reference_t<Arrays>>>())...))>,
      fcppt::container::array::size<source1>::value>;

  return fcppt::container::array::init<result_type>(
      [&_function, &_array1, &_arrays...](auto const _index) {
        FCPPT_USE(_index);

        using index = decltype(_index);

        return _function(
            fcppt::move_if_rvalue<Array1>(std::get<index::value>(_array1)),
            fcppt::move_if_rvalue<Arrays>(std::get<index::value>(_arrays))...);
      });
}

}
}
}

#endif
