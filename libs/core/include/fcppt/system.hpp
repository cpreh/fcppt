//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_SYSTEM_HPP_INCLUDED
#define FCPPT_SYSTEM_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/detail/symbol.hpp>
#include <fcppt/optional/object_impl.hpp>

namespace fcppt
{
/**
\brief Calls <code>std::system</code>.

\ingroup fcpptstring

\warning <code>std::system</code> may not be thread-safe because it may change signal settings.
*/
FCPPT_DETAIL_SYMBOL
fcppt::optional::object<int> system(fcppt::string const &);

}

#endif
