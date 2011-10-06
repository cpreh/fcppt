//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TO_STD_STRING_HPP_INCLUDED
#define FCPPT_TO_STD_STRING_HPP_INCLUDED

#include <fcppt/default_locale.hpp>
#include <fcppt/string.hpp>
#include <fcppt/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <locale>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{

FCPPT_SYMBOL
std::string const
to_std_string(
	fcppt::string const &,
	std::locale const & = fcppt::default_locale()
);

}

#endif
