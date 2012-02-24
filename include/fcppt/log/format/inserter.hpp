//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_FORMAT_INSERTER_HPP_INCLUDED
#define FCPPT_LOG_FORMAT_INSERTER_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/symbol.hpp>


namespace fcppt
{
namespace log
{
namespace format
{

FCPPT_SYMBOL
fcppt::string const
inserter(
	fcppt::string const &format_string,
	fcppt::string const &text
);

}
}
}

#endif
