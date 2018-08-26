//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_STRING_HPP_INCLUDED
#define FCPPT_STRING_HPP_INCLUDED

#include <fcppt/char_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief The string type used for text.

\ingroup fcpptstring

See the \link fcpptstring string module description \endlink for more
information about this type.
*/
typedef std::basic_string<
	fcppt::char_type
> string;

}

#endif
