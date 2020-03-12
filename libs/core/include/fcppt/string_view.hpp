//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_STRING_VIEW_HPP_INCLUDED
#define FCPPT_STRING_VIEW_HPP_INCLUDED

#include <fcppt/char_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string_view>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief The string view type used for text.

\ingroup fcpptstring

See \ref fcpptstring for more information about this type.
*/
using
string_view
=
std::basic_string_view<
	fcppt::char_type
>;

}

#endif
