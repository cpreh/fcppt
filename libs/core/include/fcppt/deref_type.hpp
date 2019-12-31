//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DEREF_TYPE_HPP_INCLUDED
#define FCPPT_DEREF_TYPE_HPP_INCLUDED

#include <fcppt/deref.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief The type of #fcppt::deref.

\ingroup fcpptvarious
*/
template<
	typename Arg
>
using
deref_type
=
decltype(
	fcppt::deref(
		std::declval<
			Arg &
		>()
	)
);

}

#endif
