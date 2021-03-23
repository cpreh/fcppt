//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ERROR_STRERROR_HPP_INCLUDED
#define FCPPT_ERROR_STRERROR_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/detail/symbol.hpp>

namespace fcppt
{
namespace error
{
/**
\brief A wrapper around <code>std::strerror</code>

\ingroup fcpptstring

A wrapper around <code>std::strerror</code> returning the message for the error
code given by \a errnum.

\a errnum The error code to return the message for
*/
FCPPT_DETAIL_SYMBOL
fcppt::string strerror(int errnum);

}
}

#endif
