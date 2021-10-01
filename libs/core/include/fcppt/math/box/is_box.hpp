//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_BOX_IS_BOX_HPP_INCLUDED
#define FCPPT_MATH_BOX_IS_BOX_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/box/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::math::box
{
/**
\brief Metafunction to test if a type is a box type
\ingroup fcpptmathbox
\tparam T The type to test against
*/
template <typename T>
struct is_box : std::false_type
{
};

template <typename T, fcppt::math::size_type N>
struct is_box<fcppt::math::box::object<T, N>> : std::true_type
{
};

}

#endif
