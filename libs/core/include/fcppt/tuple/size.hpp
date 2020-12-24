//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_TUPLE_SIZE_HPP_INCLUDED
#define FCPPT_TUPLE_SIZE_HPP_INCLUDED

#include <fcppt/tuple/impl_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <tuple>
#include <fcppt/config/external_end.hpp>

namespace fcppt::tuple
{

template<typename Tuple>
using size = std::tuple_size<fcppt::tuple::impl_type<Tuple>>;
}

#endif
