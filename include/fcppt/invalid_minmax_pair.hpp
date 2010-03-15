//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_INVALID_MINMAX_PAIR_HPP_INCLUDED
#define FCPPT_INVALID_MINMAX_PAIR_HPP_INCLUDED

#include <fcppt/exception.hpp>
#include <fcppt/string.hpp>
#include <fcppt/symbol.hpp>
#include <fcppt/class_symbol.hpp>

namespace fcppt
{

class FCPPT_CLASS_SYMBOL invalid_minmax_pair
:
	public fcppt::exception
{
public:
	FCPPT_SYMBOL explicit invalid_minmax_pair(
		fcppt::string const &
	);
};

}

#endif
