//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ARRAY_FROM_RANGE_HPP_INCLUDED
#define FCPPT_ARRAY_FROM_RANGE_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/array/init.hpp>
#include <fcppt/array/object_impl.hpp>
#include <fcppt/optional/make_if.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/range/size.hpp>
#include <fcppt/type_traits/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::array
{
/**
\brief Creates an #fcppt::array::object out of a range.

\ingroup fcpptarray

\tparam Source Must be a random-access range.
*/
template <std::size_t Size, typename Source>
fcppt::optional::object<
    fcppt::array::object<fcppt::type_traits::value_type<std::remove_cvref_t<Source>>, Size>>
from_range(Source &&_source) // NOLINT(cppcoreguidelines-missing-std-forward)
{
  return fcppt::optional::make_if(
      fcppt::range::size(_source) == Size,
      [&_source]
      {
        return fcppt::array::init<fcppt::array::object<
            fcppt::type_traits::value_type<std::remove_cvref_t<Source>>,
            Size>>([&_source]<std::size_t Index>(std::integral_constant<std::size_t, Index>)
                   { return fcppt::move_if_rvalue<Source>(_source[Index]); });
      });
}

}

#endif
