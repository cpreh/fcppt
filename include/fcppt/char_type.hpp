//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CHAR_TYPE_HPP_INCLUDED
#define FCPPT_CHAR_TYPE_HPP_INCLUDED

#include <fcppt/detail/char_type.hpp>

namespace fcppt
{

/**
\brief The char_type used for text.
\ingroup fcpptstring

Windows and Linux (for example) have different needs for their character types.
While Linux usually uses UTF-8 and therefore plain char, Windows uses UTF-16
and wchar_t. This typedef makes the underlying character type configurable. See
the \link fcpptstring string module description \endlink for more information.
*/
typedef fcppt::detail::char_type char_type;

}

#endif
