//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ARRAY_JOIN_HPP_INCLUDED
#define FCPPT_ARRAY_JOIN_HPP_INCLUDED

#include <fcppt/array/is_object.hpp>
#include <fcppt/array/object_impl.hpp>
#include <fcppt/array/size.hpp>
#include <fcppt/array/value_type.hpp>
#include <fcppt/array/detail/join.hpp>
#include <fcppt/mpl/add.hpp>
#include <fcppt/mpl/arg.hpp>
#include <fcppt/mpl/bind.hpp>
#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/list/fold.hpp>
#include <fcppt/mpl/list/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::array
{
/**
\brief Appends multiple arrays.

\ingroup fcpptarray

Let <code>a_1 = Array1</code> and <code>Arrays = a_2, ..., a_n</code>.
The result is equivalent to <code>append(a_1, ..., append(a_{n-1}, a_n) ...)</code>.

All arrays must have the same value type.

\see fcppt::array::append
*/
template <typename Array1, typename... Arrays>
fcppt::array::object<
    fcppt::array::value_type<std::remove_cvref_t<Array1>>,
    fcppt::mpl::list::fold<
        fcppt::mpl::list::object<std::remove_cvref_t<Arrays>...>,
        fcppt::mpl::bind<
            fcppt::mpl::lambda<fcppt::mpl::add>,
            fcppt::mpl::bind<fcppt::mpl::lambda<fcppt::array::size>, fcppt::mpl::arg<1>>,
            fcppt::mpl::arg<2>>,
        fcppt::array::size<std::remove_cvref_t<Array1>>>::value>
join(Array1 &&_array1, Arrays &&..._arrays)
  requires(std::conjunction_v<
           fcppt::array::is_object<std::remove_cvref_t<Array1>>,
           fcppt::array::is_object<std::remove_cvref_t<Arrays>>...,
           std::is_same<
               fcppt::array::value_type<std::remove_cvref_t<Array1>>,
               fcppt::array::value_type<std::remove_cvref_t<Arrays>>>...>)
{
  return fcppt::array::detail::join(
      std::forward<Array1>(_array1), std::forward<Arrays>(_arrays)...);
}
}

#endif
