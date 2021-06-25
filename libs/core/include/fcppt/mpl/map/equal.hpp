//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_MAP_EQUAL_HPP_INCLUDED
#define FCPPT_MPL_MAP_EQUAL_HPP_INCLUDED

#include <fcppt/mpl/apply.hpp>
#include <fcppt/mpl/arg.hpp>
#include <fcppt/mpl/bind.hpp>
#include <fcppt/mpl/constant.hpp>
#include <fcppt/mpl/if.hpp>
#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/list/all_of.hpp>
#include <fcppt/mpl/map/at.hpp>
#include <fcppt/mpl/map/keys.hpp>
#include <fcppt/mpl/map/object_concept.hpp>
#include <fcppt/mpl/set/equal.hpp>
#include <fcppt/mpl/set/to_list.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::mpl::map
{
namespace detail::equal_impl
{
template <typename Map1, typename Map2>
using map_same_values = fcppt::mpl::list::all_of<
    fcppt::mpl::set::to_list<fcppt::mpl::map::keys<Map1>>,
    fcppt::mpl::bind<
        fcppt::mpl::lambda<std::is_same>,
        fcppt::mpl::bind<
            fcppt::mpl::lambda<fcppt::mpl::map::at>,
            fcppt::mpl::constant<Map1>,
            fcppt::mpl::arg<0>>,
        fcppt::mpl::bind<
            fcppt::mpl::lambda<fcppt::mpl::map::at>,
            fcppt::mpl::constant<Map2>,
            fcppt::mpl::arg<0>>>>;
}
/**
\brief Checks if two mpl maps are equal.

\ingroup fcpptmpl

Two maps are equal if and only if they contain the same key-value pairs.
*/
template <fcppt::mpl::map::object_concept Map1, fcppt::mpl::map::object_concept Map2>
using equal = fcppt::mpl::apply<fcppt::mpl::if_<
    fcppt::mpl::set::equal<fcppt::mpl::map::keys<Map1>, fcppt::mpl::map::keys<Map2>>,
    fcppt::mpl::bind<
        fcppt::mpl::lambda<fcppt::mpl::map::detail::equal_impl::map_same_values>,
        fcppt::mpl::constant<Map1>,
        fcppt::mpl::constant<Map2>>,
    fcppt::mpl::constant<std::false_type>>>;
}

#endif
