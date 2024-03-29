//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_TO_ARRAY_TYPE_HPP_INCLUDED
#define FCPPT_MATH_TO_ARRAY_TYPE_HPP_INCLUDED

#include <fcppt/array/object_impl.hpp>
#include <fcppt/math/detail/storage_size.hpp>

namespace fcppt::math
{
/**
\brief Returns the array type of an object with static storage

\ingroup fcpptmath
*/
template <typename Type>
using to_array_type = fcppt::array::object<
    typename Type::value_type,
    fcppt::math::detail::storage_size<typename Type::storage_type>::value>;

}

#endif
