//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ARRAY_IS_OBJECT_HPP_INCLUDED
#define FCPPT_ARRAY_IS_OBJECT_HPP_INCLUDED

#include <fcppt/array/detail/is_object.hpp>

namespace fcppt::array
{
/**
\brief Tests whether a type is a array.
\ingroup fcpptarray
*/
template <typename T>
using is_object = typename fcppt::array::detail::is_object<T>::type;
}

#endif
