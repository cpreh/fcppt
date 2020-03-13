//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_STRING_FWD_HPP_INCLUDED
#define FCPPT_OPTIONAL_STRING_FWD_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/optional/object_fwd.hpp>


namespace fcppt
{

/**
\brief An optional string.

\ingroup fcpptstring
*/
using
optional_string
=
fcppt::optional::object<
	fcppt::string
>;

}

#endif
