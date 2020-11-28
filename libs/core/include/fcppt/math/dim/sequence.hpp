//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_DIM_SEQUENCE_HPP_INCLUDED
#define FCPPT_MATH_DIM_SEQUENCE_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/sequence.hpp>
#include <fcppt/math/dim/object_impl.hpp>
#include <fcppt/math/dim/static.hpp>
#include <fcppt/optional/object_impl.hpp>

namespace fcppt
{
namespace math
{
namespace dim
{
/**
\brief Sequence for a dim.

\ingroup fcpptmathdim

Uses #fcppt::optional::sequence.
*/
template <typename T, fcppt::math::size_type N, typename S>
inline fcppt::optional::object<fcppt::math::dim::static_<T, N>>
sequence(fcppt::math::dim::object<fcppt::optional::object<T>, N, S> const &_value)
{
  return fcppt::math::detail::sequence<fcppt::math::dim::static_<T, N>>(_value);
}

}
}
}

#endif
