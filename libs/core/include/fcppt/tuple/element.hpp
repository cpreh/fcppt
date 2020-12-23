//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_TUPLE_ELEMENT_HPP_INCLUDED
#define FCPPT_TUPLE_ELEMENT_HPP_INCLUDED

#include <fcppt/tuple/is_object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <tuple>
#include <fcppt/config/external_end.hpp>

namespace fcppt::tuple
{
/**
\brief The type of the I'th element of a tuple.
\ingroup fcppttuple
*/
template <std::size_t I, typename T, typename = fcppt::tuple::is_object<T>>
using element = std::tuple_element_t<I, typename T::impl_type>;
}

#endif
