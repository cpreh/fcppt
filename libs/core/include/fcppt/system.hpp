//          Copyright Carl Philipp Reh 2009 - 2020.
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
\brief Calls std::system.

\ingroup fcpptstring
*/
FCPPT_DETAIL_SYMBOL
fcppt::optional::object<
	int
>
system(
	fcppt::string const &
);

}

#endif
