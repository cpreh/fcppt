//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DECLTYPE_SINK_HPP_INCLUDED
#define FCPPT_DECLTYPE_SINK_HPP_INCLUDED

#include <fcppt/detail/decltype_sink.hpp>


// TODO: Remove this
/**
\brief Return <code>decltype</code> of an argument and use it

\ingroup fcpptvarious
*/
#define FCPPT_DECLTYPE_SINK(\
	name\
)\
decltype(\
	fcppt::detail::decltype_sink(\
		name\
	)\
)

#endif
