//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_TUPLE_SIZE_HPP_INCLUDED
#define FCPPT_TUPLE_SIZE_HPP_INCLUDED

#include <fcppt/tuple/impl_type.hpp>
#include <fcppt/tuple/is_object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <tuple>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::tuple
{

template<typename Tuple, typename = std::enable_if_t<fcppt::tuple::is_object<Tuple>::value>>
using size = std::integral_constant<std::size_t,std::tuple_size_v<fcppt::tuple::impl_type<Tuple>>>;
}

#endif
