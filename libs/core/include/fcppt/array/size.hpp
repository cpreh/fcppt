//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ARRAY_SIZE_HPP_INCLUDED
#define FCPPT_ARRAY_SIZE_HPP_INCLUDED

#include <fcppt/array/is_object.hpp>
#include <fcppt/array/object_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::array
{
/**
\brief Gets the size of an array.

\ingroup fcpptrarray
*/
template <typename Array, typename = std::enable_if_t<fcppt::array::is_object<Array>::value>>
using size = std::tuple_size<typename Array::impl_type>;

}

#endif
