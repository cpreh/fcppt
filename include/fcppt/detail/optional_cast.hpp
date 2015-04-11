//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_OPTIONAL_CAST_HPP_INCLUDED
#define FCPPT_DETAIL_OPTIONAL_CAST_HPP_INCLUDED

#include <fcppt/optional_fwd.hpp>


#define FCPPT_DETAIL_OPTIONAL_CAST(\
	cast_type\
)\
_optional.has_value() \
? \
	fcppt::optional< \
		Result & \
	>( \
		cast_type< \
			Result & \
		>( \
			_optional.get_unsafe() \
		) \
	) \
: \
	fcppt::optional< \
		Result & \
	>()

#endif
