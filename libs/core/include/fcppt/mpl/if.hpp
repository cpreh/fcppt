//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_IF_HPP_INCLUDED
#define FCPPT_MPL_IF_HPP_INCLUDED

#include <fcppt/mpl/bool_concept.hpp>

namespace fcppt::mpl
{

template<fcppt::mpl::bool_concept B, typename T, typename F>
using if_ = std::conditional_t<B::value, T, F>;

}

#endif
