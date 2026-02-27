//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ENUM_INDEX_OF_ARRAY_HPP_INCLUDED
#define FCPPT_ENUM_INDEX_OF_ARRAY_HPP_INCLUDED

#include <fcppt/algorithm/index_of.hpp>
#include <fcppt/cast/int_to_enum.hpp>
#include <fcppt/enum/array_impl.hpp>
#include <fcppt/optional/map.hpp>
#include <fcppt/optional/object_impl.hpp>

namespace fcppt::enum_
{
/**
\brief Returns the enum of the first element found in an enum array.

\ingroup fcpptenum

Searches for \a _value in \a _array and returns the index of the first
occurrence as an enum if there is any, otherwise returns the empty optional.
*/
template <typename Enum, typename Value>
inline fcppt::optional::object<Enum>
index_of_array(fcppt::enum_::array<Enum, Value> const &_array, Value const &_value)
{
  return fcppt::optional::map(
      fcppt::algorithm::index_of(_array.impl(), _value),
      [](fcppt::enum_::array<Enum, Value>::internal::size_type const _index) {
        return fcppt::cast::int_to_enum<Enum>(_index);
      });
}

}

#endif
