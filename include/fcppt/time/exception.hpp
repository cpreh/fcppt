//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TIME_EXCEPTION_HPP_INCLUDED
#define FCPPT_TIME_EXCEPTION_HPP_INCLUDED

#include <fcppt/exception.hpp>
#include <fcppt/string.hpp>
#include <fcppt/symbol.hpp>
#include <fcppt/class_symbol.hpp>

namespace fcppt
{
namespace time
{

class FCPPT_CLASS_SYMBOL exception
:
	public fcppt::exception
{
public:
	FCPPT_SYMBOL explicit exception(
		fcppt::string const &
	);
};

}
}

#endif
