//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_DETAIL_STRING_TYPES_HPP_INCLUDED
#define FCPPT_DETAIL_STRING_TYPES_HPP_INCLUDED

#include <fcppt/detail/char_types.hpp>
#include <fcppt/mpl/bind.hpp>
#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/list/map.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::detail
{
using string_types = fcppt::mpl::list::map<
    fcppt::detail::char_types,
    fcppt::mpl::bind<fcppt::mpl::lambda<std::add_pointer_t>, fcppt::mpl::lambda<std::add_const_t>>>;
}

#endif
