//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_EXCEPTION_HPP_INCLUDED
#define FCPPT_LOG_EXCEPTION_HPP_INCLUDED

#include <fcppt/exception.hpp>
#include <fcppt/string.hpp>
#include <fcppt/symbol.hpp>

namespace fcppt
{
namespace log
{

/// The exception base class for logger exceptions
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
