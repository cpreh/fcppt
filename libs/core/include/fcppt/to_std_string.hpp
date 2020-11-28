//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_TO_STD_STRING_HPP_INCLUDED
#define FCPPT_TO_STD_STRING_HPP_INCLUDED

#include <fcppt/optional_std_string.hpp>
#include <fcppt/string_view.hpp>
#include <fcppt/detail/symbol.hpp>

namespace fcppt
{
/**
\brief Convert from #fcppt::string to std::string using #fcppt::string_conv_locale.
\ingroup fcpptstring

See \ref fcpptstring for more information about this function.
*/
FCPPT_DETAIL_SYMBOL
fcppt::optional_std_string to_std_string(fcppt::string_view const &);

}

#endif
