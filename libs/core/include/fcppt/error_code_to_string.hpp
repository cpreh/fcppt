//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ERROR_CODE_TO_STRING_HPP_INCLUDED
#define FCPPT_ERROR_CODE_TO_STRING_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/detail/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <system_error>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
/**
\brief Converts an error code to an fcppt::string.

\ingroup fcpptstring
*/
FCPPT_DETAIL_SYMBOL
fcppt::string error_code_to_string(std::error_code const &);

}

#endif
