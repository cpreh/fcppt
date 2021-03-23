//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_DETAIL_CHECK_SUB_COMMAND_NAMES_HPP_INCLUDED
#define FCPPT_OPTIONS_DETAIL_CHECK_SUB_COMMAND_NAMES_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/options/detail/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace options
{
namespace detail
{
FCPPT_OPTIONS_DETAIL_SYMBOL
void check_sub_command_names(std::vector<fcppt::string> const &);

}
}
}

#endif
