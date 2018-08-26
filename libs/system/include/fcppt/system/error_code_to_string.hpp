//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SYSTEM_ERROR_CODE_TO_STRING_HPP_INCLUDED
#define FCPPT_SYSTEM_ERROR_CODE_TO_STRING_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/system/detail/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/system/error_code.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace system
{

/**
\brief Converts an error code to a string.

\ingroup fcpptsystem
*/
FCPPT_SYSTEM_DETAIL_SYMBOL
fcppt::string
error_code_to_string(
	boost::system::error_code const &
);

}
}

#endif
