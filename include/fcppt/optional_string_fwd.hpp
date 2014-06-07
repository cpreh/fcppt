//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_STRING_FWD_HPP_INCLUDED
#define FCPPT_OPTIONAL_STRING_FWD_HPP_INCLUDED

#include <fcppt/optional_fwd.hpp>
#include <fcppt/string.hpp>


namespace fcppt
{

/**
\brief An optional string.

\ingroup fcpptstring
*/
typedef fcppt::optional<
	fcppt::string
> optional_string;

}

#endif
