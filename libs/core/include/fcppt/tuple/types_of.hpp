//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_TUPLE_TYPES_OF_HPP_INCLUDED
#define FCPPT_TUPLE_TYPES_OF_HPP_INCLUDED

#include <fcppt/tuple/is_object.hpp>
#include <fcppt/tuple/detail/types_of.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::tuple
{

/**
\brief The types of a tuple as an <code>mpl::list</code>.
\ingroup fcppttuple
*/
template<typename T, typename = std::enable_if_t<fcppt::tuple::is_object<T>::value>>
using types_of = typename fcppt::tuple::detail::types_of<T>::type;
}

#endif
