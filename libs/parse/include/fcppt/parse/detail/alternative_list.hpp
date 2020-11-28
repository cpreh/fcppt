//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_DETAIL_ALTERNATIVE_LIST_HPP_INCLUDED
#define FCPPT_PARSE_DETAIL_ALTERNATIVE_LIST_HPP_INCLUDED

#include <fcppt/parse/detail/alternative_list_impl.hpp>

namespace fcppt
{
namespace parse
{
namespace detail
{
template <typename T>
using alternative_list = typename fcppt::parse::detail::alternative_list_impl<T>::type;

}
}
}

#endif
