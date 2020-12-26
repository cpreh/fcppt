//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ARRAY_INIT_HPP_INCLUDED
#define FCPPT_ARRAY_INIT_HPP_INCLUDED

#include <fcppt/array/size.hpp>
#include <fcppt/array/detail/init.hpp>
#include <fcppt/type_traits/is_std_array.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::array
{
/**
\brief Constructs an array by calling a function with static indices.

\ingroup fcpptarray

Constructs an array of type \a Array by calling
<code>_function(std::integral_constant<std::size_t, Index>)</code> for every
index.

\tparam Array Must be a <code>std::array</code>.

\tparam Function Must be a function callable as <code>Array::value_type
(std::integral_constant<std::size_t, I>)</code>.
*/
template <
    typename Array,
    typename Function,
    typename = std::enable_if<fcppt::array::is_object<Array>::value>>
inline Array init(Function const &_function)
{
  return // NOLINT(clang-analyzer-cplusplus.NewDeleteLeaks)
      fcppt::array::detail::init<Array>(
          std::make_index_sequence<fcppt::array::size<Array>::value>{}, _function);
}
}

#endif
