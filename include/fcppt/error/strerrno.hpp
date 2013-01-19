//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ERROR_STRERRNO_HPP_INCLUDED
#define FCPPT_ERROR_STRERRNO_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/symbol.hpp>

namespace fcppt
{
namespace error
{

/**
\brief A wrapper around <code>std::strerror(strerrno)</code>

\ingroup fcpptstring

A wrapper around <code>std::strerror(strerrno)</code> returning the message for
the current global error number.
*/
FCPPT_SYMBOL
fcppt::string const
strerrno();

}
}

#endif
