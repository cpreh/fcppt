//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_DETAIL_HELP_ERROR_HPP_INCLUDED
#define FCPPT_OPTIONS_DETAIL_HELP_ERROR_HPP_INCLUDED

#include <fcppt/options/error.hpp>
#include <fcppt/options/help_switch_fwd.hpp>
#include <fcppt/options/detail/symbol.hpp>


namespace fcppt
{
namespace options
{
namespace detail
{

FCPPT_OPTIONS_DETAIL_SYMBOL
fcppt::options::error
help_error(
	fcppt::options::help_switch const &,
	fcppt::options::error &&
);

}
}
}

#endif
