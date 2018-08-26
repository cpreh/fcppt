//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SYSTEM_MAKE_OPTIONAL_ERROR_CODE_HPP_INCLUDED
#define FCPPT_SYSTEM_MAKE_OPTIONAL_ERROR_CODE_HPP_INCLUDED

#include <fcppt/system/optional_error_code.hpp>
#include <fcppt/system/detail/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/system/error_code.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace system
{

/**
\brief Creates an optional error code.

\ingroup fcpptsystem

If \a error has an error value, then it is returned as an optional. Otherwise,
\a error contains <code>Success</code> and the empty optional is returned.
*/
FCPPT_SYSTEM_DETAIL_SYMBOL
fcppt::system::optional_error_code
make_optional_error_code(
	boost::system::error_code const &error
);

}
}

#endif
