//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_TUPLE_IMPL_TYPE_HPP_INCLUDED
#define FCPPT_TUPLE_IMPL_TYPE_HPP_INCLUDED

#include <fcppt/tuple/is_object.hpp>
#include <fcppt/tuple/object_decl.hpp> // IWYU pragma: keep
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::tuple
{
template <typename T, typename = std::enable_if_t<fcppt::tuple::is_object<T>::value>>
using impl_type = T::impl_type;
}

#endif
