//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_STD_STRING_FWD_HPP_INCLUDED
#define FCPPT_OPTIONAL_STD_STRING_FWD_HPP_INCLUDED

#include <fcppt/optional/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief An optional std string.

\ingroup fcpptstring
*/
typedef
fcppt::optional::object<
	std::string
>
optional_std_string;

}

#endif
