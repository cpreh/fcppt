//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_DETAIL_CAST_HPP_INCLUDED
#define FCPPT_OPTIONAL_DETAIL_CAST_HPP_INCLUDED

#include <fcppt/make_ref.hpp>
#include <fcppt/optional/reference.hpp>


#define FCPPT_OPTIONAL_DETAIL_CAST(\
	cast_type\
)\
_optional.has_value() \
? \
	fcppt::optional::reference< \
		Result \
	>( \
		fcppt::make_ref( \
			cast_type< \
				Result & \
			>( \
				_optional.get_unsafe().get() \
			) \
		) \
	) \
: \
	fcppt::optional::reference< \
		Result \
	>()

#endif
