//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_DETAIL_HELP_TEXT_HPP_INCLUDED
#define FCPPT_OPTIONS_DETAIL_HELP_TEXT_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/options/optional_help_text_fwd.hpp>
#include <fcppt/options/detail/symbol.hpp>


namespace fcppt
{
namespace options
{
namespace detail
{

FCPPT_OPTIONS_DETAIL_SYMBOL
fcppt::string
help_text(
	fcppt::options::optional_help_text const &
);

}
}
}

#endif
