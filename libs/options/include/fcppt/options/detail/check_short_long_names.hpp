//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_DETAIL_CHECK_SHORT_LONG_NAMES_HPP_INCLUDED
#define FCPPT_OPTIONS_DETAIL_CHECK_SHORT_LONG_NAMES_HPP_INCLUDED

#include <fcppt/options/long_name_fwd.hpp>
#include <fcppt/options/optional_short_name_fwd.hpp>
#include <fcppt/options/detail/symbol.hpp>

namespace fcppt
{
namespace options
{
namespace detail
{
FCPPT_OPTIONS_DETAIL_SYMBOL
void check_short_long_names(
    fcppt::options::optional_short_name const &, fcppt::options::long_name const &);

}
}
}

#endif
