//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_METAL_MAPS_EQUAL_HPP_INCLUDED
#define FCPPT_METAL_MAPS_EQUAL_HPP_INCLUDED

#include <fcppt/metal/detail/map_same_values.hpp>
#include <fcppt/metal/set/from_list_relaxed.hpp>
#include <fcppt/metal/set/make.hpp>
#include <fcppt/metal/set/symmetric_difference.hpp>
#include <fcppt/type_traits/to_bool.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace metal
{
/**
\brief Checks if two metal::maps are equal.

\ingroup fcpptmetal

Two maps are equal if and only if they contain the same key-value pairs.
The order in which they occur does not matter.

\tparam Map1 Must be a metal::map.

\tparam Map2 Must be a metal::map.
*/
template <typename Map1, typename Map2>
using maps_equal = fcppt::type_traits::to_bool<::metal::invoke<::metal::if_<
    ::metal::as_number<std::is_same<
        fcppt::metal::set::symmetric_difference<
            fcppt::metal::set::from_list_relaxed<::metal::keys<Map1>>,
            fcppt::metal::set::from_list_relaxed<::metal::keys<Map2>>>,
        fcppt::metal::set::make<>>>,
    ::metal::bind<
        ::metal::lambda<fcppt::metal::detail::map_same_values>,
        ::metal::always<Map1>,
        ::metal::always<Map2>>,
    ::metal::always<::metal::false_>>>>;

}
}

#endif
