//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RECORD_DETAIL_MAP_RESULT_HPP_INCLUDED
#define FCPPT_RECORD_DETAIL_MAP_RESULT_HPP_INCLUDED

#include <fcppt/record/element_to_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::record::detail
{
template <typename Function, typename Arg>
using map_result = std::invoke_result_t<Function,fcppt::record::element_to_type<Arg>>;

}

#endif
