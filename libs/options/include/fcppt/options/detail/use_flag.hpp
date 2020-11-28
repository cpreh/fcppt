//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_DETAIL_USE_FLAG_HPP_INCLUDED
#define FCPPT_OPTIONS_DETAIL_USE_FLAG_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>
#include <fcppt/string_view.hpp>
#include <fcppt/options/state_fwd.hpp>
#include <fcppt/options/detail/flag_is_short.hpp>
#include <fcppt/options/detail/symbol.hpp>

namespace fcppt
{
namespace options
{
namespace detail
{
[[nodiscard]] FCPPT_OPTIONS_DETAIL_SYMBOL bool use_flag(
    fcppt::reference<fcppt::options::state>,
    fcppt::string_view const &,
    fcppt::options::detail::flag_is_short);

}
}
}

#endif
