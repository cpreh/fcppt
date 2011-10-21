//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_NAME_HPP_INCLUDED
#define FCPPT_TYPE_NAME_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/symbol.hpp>
#include <fcppt/type_info.hpp>


namespace fcppt
{

FCPPT_SYMBOL string const
type_name(
	type_info const &);

}

#endif
