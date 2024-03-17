//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_BOX_HAS_DIM_HPP_INCLUDED
#define FCPPT_MATH_BOX_HAS_DIM_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/box/object_fwd.hpp>
#include <fcppt/math/detail/dim_matches.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::math::box
{
/**
\brief Metafunction to check the dimension of a box

\ingroup fcpptmathbox
*/
template <typename Box, fcppt::math::size_type Dim>
struct has_dim : std::false_type
{
};

template <typename T, fcppt::math::size_type N, fcppt::math::size_type Dim>
struct has_dim<fcppt::math::box::object<T, N>, Dim> : fcppt::math::detail::dim_matches<Dim, N>
{
};

}

#endif
