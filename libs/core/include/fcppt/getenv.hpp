//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_GETENV_HPP_INCLUDED
#define FCPPT_GETENV_HPP_INCLUDED

#include <fcppt/optional_std_string.hpp>
#include <fcppt/detail/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string_view>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
/**
\brief Gets an optional value from the environment.

\ingroup fcpptvarious

\warning This function calls <code>std::getenv</code> which is not thread-safe.
You must ensure that this function is not called concurrently with any function
that modifies the environment.
*/
FCPPT_DETAIL_SYMBOL
fcppt::optional_std_string getenv(std::string_view);

}

#endif
