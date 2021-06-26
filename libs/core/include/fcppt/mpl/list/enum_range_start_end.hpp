//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_ENUM_RANGE_START_END_HPP_INCLUDED
#define FCPPT_MPL_LIST_ENUM_RANGE_START_END_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/cast/enum_to_int.hpp>
#include <fcppt/cast/int_to_enum_fun.hpp>
#include <fcppt/mpl/arg.hpp>
#include <fcppt/mpl/bind.hpp>
#include <fcppt/mpl/constant.hpp>
#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/list/interval.hpp>
#include <fcppt/mpl/list/map.hpp>
#include <fcppt/type_traits/integral_cast.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::mpl::list
{
/**
\brief An mpl list over enums from a minimum to a maximum.

\ingroup fcpptenum
TODO(concepts)
*/
template <typename Enum, Enum Start, Enum Max>
using enum_range_start_end = fcppt::mpl::list::map<
    fcppt::mpl::list::interval<
        std::underlying_type_t<Enum>,
        fcppt::cast::enum_to_int<std::underlying_type_t<Enum>>(Start),
        fcppt::cast::enum_to_int<std::underlying_type_t<Enum>>(Max) +
            fcppt::literal<std::underlying_type_t<Enum>>(1)>,
    fcppt::mpl::bind<
        fcppt::mpl::lambda<fcppt::type_traits::integral_cast>,
        fcppt::mpl::constant<Enum>,
        fcppt::mpl::constant<fcppt::cast::int_to_enum_fun>,
        fcppt::mpl::arg<1>>>;
}

#endif
