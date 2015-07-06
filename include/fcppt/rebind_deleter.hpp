//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_REBIND_DELETER_HPP_INCLUDED
#define FCPPT_REBIND_DELETER_HPP_INCLUDED

#include <fcppt/detail/rebind_deleter.hpp>


namespace fcppt
{

/**
\brief Converts a deleter

\ingroup fcpptsmartptr
*/
template<
	typename Result,
	typename Deleter
>
using
rebind_deleter
=
typename
fcppt::detail::rebind_deleter<
	Result,
	Deleter
>::type;

}

#endif
