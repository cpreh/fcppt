//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_OPTION_NAME_COMPARISON_HPP_INCLUDED
#define FCPPT_OPTIONS_OPTION_NAME_COMPARISON_HPP_INCLUDED

#include <fcppt/options/option_name_fwd.hpp>
#include <fcppt/options/detail/symbol.hpp>


namespace fcppt
{
namespace options
{

FCPPT_OPTIONS_DETAIL_SYMBOL
bool
operator==(
	fcppt::options::option_name const &,
	fcppt::options::option_name const &
);

FCPPT_OPTIONS_DETAIL_SYMBOL
bool
operator<(
	fcppt::options::option_name const &,
	fcppt::options::option_name const &
);

}
}

#endif
