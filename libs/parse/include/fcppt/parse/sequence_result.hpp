//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_SEQUENCE_RESULT_HPP_INCLUDED
#define FCPPT_PARSE_SEQUENCE_RESULT_HPP_INCLUDED

#include <fcppt/parse/detail/sequence_result.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace parse
{
template <typename Left, typename Right>
using sequence_result =
    decltype(fcppt::parse::detail::sequence_result(std::declval<Left>(), std::declval<Right>()));

}
}

#endif
