//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ARRAY_PUSH_BACK_HPP_INCLUDED
#define FCPPT_ARRAY_PUSH_BACK_HPP_INCLUDED

#include <fcppt/array/append.hpp>
#include <fcppt/array/is_object.hpp>
#include <fcppt/array/make.hpp>
#include <fcppt/array/object_impl.hpp>
#include <fcppt/array/size.hpp>
#include <fcppt/array/value_type.hpp>
#include <fcppt/type_traits/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::array
{
/**
\brief Pushes a new element to the back of an array.

\ingroup fcpptarray

Pushes \a _new_element to the back of \a _source.

\tparam NewElement Must be the same as <code>value_type<Source></code>
*/
template <
    typename Source,
    typename NewElement,
    typename = std::enable_if_t<std::conjunction_v<
        fcppt::array::is_object<std::remove_cvref_t<Source>>,
        std::is_same<
            std::remove_cvref_t<NewElement>,
            fcppt::array::value_type<std::remove_cvref_t<Source>>>>>>
[[nodiscard]] fcppt::array::object<
    fcppt::type_traits::value_type<std::remove_cvref_t<Source>>,
    fcppt::array::size<std::remove_cvref_t<Source>>::value + 1U>
push_back(Source &&_source, NewElement &&_new_element)
{
  return fcppt::array::append(
      std::forward<Source>(_source), fcppt::array::make(std::forward<NewElement>(_new_element)));
}
}

#endif
