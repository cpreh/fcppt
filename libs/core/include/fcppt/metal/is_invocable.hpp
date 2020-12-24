//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_METAL_IS_INVOCABLE_HPP_INCLUDED
#define FCPPT_METAL_IS_INVOCABLE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::metal
{

template<typename F, typename L>
using is_invocable = ::metal::apply<::metal::lambda<std::is_invocable>,::metal::prepend<L,F>>;

}

#endif
