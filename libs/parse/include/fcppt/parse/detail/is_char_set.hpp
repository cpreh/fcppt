//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_DETAIL_IS_CHAR_SET_HPP_INCLUDED
#define FCPPT_PARSE_DETAIL_IS_CHAR_SET_HPP_INCLUDED

#include <fcppt/parse/basic_char_set_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace parse
{
namespace detail
{
template <typename>
struct is_char_set : std::false_type
{
};

template <typename Ch>
struct is_char_set<fcppt::parse::basic_char_set<Ch>> : std::true_type
{
};

}
}
}

#endif
