//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_DETAIL_SEQUENCE_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_SEQUENCE_HPP_INCLUDED

#include <fcppt/algorithm/map_array.hpp> // IWYU pragma: keep
#include <fcppt/math/from_array.hpp>
#include <fcppt/math/to_array.hpp>
#include <fcppt/math/to_array_type.hpp>
#include <fcppt/optional/map.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/optional/sequence.hpp>

namespace fcppt::math::detail
{
template <typename Dest, typename Source>
fcppt::optional::object<Dest> sequence(Source const &_source)
{
  using temp_array = fcppt::math::to_array_type<Dest>;

  return fcppt::optional::map(
      fcppt::optional::sequence<temp_array>(fcppt::math::to_array(_source)),
      [](temp_array const &_result) { return fcppt::math::from_array<Dest>(_result); });
}

}

#endif
