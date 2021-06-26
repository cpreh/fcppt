//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_DETAIL_ALTERNATIVE_RESULT_HPP_INCLUDED
#define FCPPT_PARSE_DETAIL_ALTERNATIVE_RESULT_HPP_INCLUDED

#include <fcppt/mpl/list/front.hpp>
#include <fcppt/mpl/list/size.hpp>
#include <fcppt/variant/from_list_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace parse
{
namespace detail
{
template <typename List>
using alternative_result = std::conditional_t<
    fcppt::mpl::list::size<List>::value == 1U,
    fcppt::mpl::list::front<List>,
    fcppt::variant::from_list<List>>;

}
}
}

#endif
