//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_SET_OBJECT_FWD_HPP_INCLUDED
#define FCPPT_MPL_SET_OBJECT_FWD_HPP_INCLUDED

#include <fcppt/mpl/set/unique.hpp>

namespace fcppt::mpl::set
{
/**
\brief The set type used by this library.
\ingroup fcpptmpl
A map is constructed from a variadic list of types, which must be pairwise disjoint.
*/
template <typename... Args>
requires fcppt::mpl::set::unique<Args...>::value
struct object;
}

#endif
