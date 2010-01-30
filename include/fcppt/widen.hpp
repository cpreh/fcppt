//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_WIDEN_HPP_INCLUDED
#define FCPPT_WIDEN_HPP_INCLUDED

#include <fcppt/symbol.hpp>
#include <string>

namespace fcppt
{

/// convert an std::string to std::wstring using the default locale
FCPPT_SYMBOL std::wstring const
widen(
	std::string const &
);

}

#endif
