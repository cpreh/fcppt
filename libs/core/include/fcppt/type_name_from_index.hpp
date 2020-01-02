//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_NAME_FROM_INDEX_HPP_INCLUDED
#define FCPPT_TYPE_NAME_FROM_INDEX_HPP_INCLUDED

#include <fcppt/detail/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <typeindex>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Returns a demangled type name if possible

\ingroup fcpptvarious
*/
FCPPT_DETAIL_SYMBOL
std::string
type_name_from_index(
	std::type_index const &
);

}

#endif
