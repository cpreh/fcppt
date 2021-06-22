//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_SET_EQUAL_HPP_INCLUDED
#define FCPPT_MPL_SET_EQUAL_HPP_INCLUDED

#include <fcppt/mpl/set/object_concept.hpp>
#include <fcppt/mpl/set/object_fwd.hpp>
#include <fcppt/mpl/set/symmetric_difference.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::mpl::set
{
template <fcppt::mpl::set::object_concept Set1, fcppt::mpl::set::object_concept Set2>
using equal =
    std::is_same<fcppt::mpl::set::symmetric_difference<Set1, Set2>, fcppt::mpl::set::object<>>;
}

#endif
