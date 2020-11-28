//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_METAL_SET_UNION_HPP_INCLUDED
#define FCPPT_METAL_SET_UNION_HPP_INCLUDED

#include <fcppt/metal/set/insert_relaxed.hpp>
#include <fcppt/metal/set/to_list.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace metal
{
namespace set
{
/**
\brief The union of two sets.

\ingroup fcpptmetal

The result contains every element that is in \a Set1 or in \a Set2.

\tparam Set1 Must be a metal set.

\tparam Set2 Must be a metal set.
*/
template <typename Set1, typename Set2>
using union_ = ::metal::accumulate<
    ::metal::bind<::metal::lambda<fcppt::metal::set::insert_relaxed>, ::metal::_1, ::metal::_2>,
    Set1,
    fcppt::metal::set::to_list<Set2>>;

}
}
}

#endif
