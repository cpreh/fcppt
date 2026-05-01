//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_IMPL_OPTION_NAME_VIEW_HPP_INCLUDED
#define FCPPT_OPTIONS_IMPL_OPTION_NAME_VIEW_HPP_INCLUDED

#include <fcppt/string_view.hpp>
#include <fcppt/options/is_short.hpp>
#include <fcppt/options/option_name_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::options::impl
{
[[nodiscard]]
std::pair<fcppt::options::is_short, fcppt::string_view>
option_name_view(fcppt::options::option_name const &);
}

#endif
