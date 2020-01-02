//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MAKE_OPTIONAL_ERROR_CODE_HPP_INCLUDED
#define FCPPT_MAKE_OPTIONAL_ERROR_CODE_HPP_INCLUDED

#include <fcppt/optional_error_code.hpp>
#include <fcppt/detail/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <system_error>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Creates an optional error code.

\ingroup fcpptvarious

If \a error has an error value, then it is returned as an optional. Otherwise,
the empty optional is returned.
*/
FCPPT_DETAIL_SYMBOL
fcppt::optional_error_code
make_optional_error_code(
	std::error_code const &error
);

}

#endif
