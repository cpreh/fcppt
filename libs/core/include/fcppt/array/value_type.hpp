//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ARRAY_VALUE_TYPE_HPP_INCLUDED
#define FCPPT_ARRAY_VALUE_TYPE_HPP_INCLUDED

#include <fcppt/array/is_object.hpp>
#include <fcppt/array/object_decl.hpp>
#include <fcppt/type_traits/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::array
{

/**
\brief The value type of an array.
\ingroup fcpptarray
*/
template<typename Array, typename = std::enable_if_t<fcppt::array::is_object<Array>::value>>
using value_type = fcppt::type_traits::value_type<Array>;

}

#endif
