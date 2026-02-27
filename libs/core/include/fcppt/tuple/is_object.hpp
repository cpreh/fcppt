//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_TUPLE_IS_OBJECT_HPP_INCLUDED
#define FCPPT_TUPLE_IS_OBJECT_HPP_INCLUDED

#include <fcppt/tuple/detail/is_object.hpp>

namespace fcppt::tuple
{
/**
\brief Tests whether a type is a tuple.
\ingroup fcppttuple
*/
template <typename T>
using is_object = fcppt::tuple::detail::is_object<T>::type;
}

#endif
