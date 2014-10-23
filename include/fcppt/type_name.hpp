//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_NAME_HPP_INCLUDED
#define FCPPT_TYPE_NAME_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/detail/symbol.hpp>


namespace fcppt
{

/**
\brief Returns a demangled type name if possible
*/
FCPPT_DETAIL_SYMBOL
fcppt::string
type_name(
	char const *
);

}

#endif
