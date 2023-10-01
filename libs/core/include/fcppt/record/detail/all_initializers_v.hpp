//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RECORD_DETAIL_ALL_INITIALIZERS_V_HPP_INCLUDED
#define FCPPT_RECORD_DETAIL_ALL_INITIALIZERS_V_HPP_INCLUDED

#include <fcppt/record/detail/all_initializers.hpp>

namespace fcppt::record::detail
{
template <typename Elements, typename Args>
constexpr inline bool all_initializers_v =
// NOLINTNEXTLINE(modernize-type-traits)
    fcppt::record::detail::all_initializers<Elements, Args>::value;
}

#endif
