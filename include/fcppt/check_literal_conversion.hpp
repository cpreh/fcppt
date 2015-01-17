//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CHECK_LITERAL_CONVERSION_HPP_INCLUDED
#define FCPPT_CHECK_LITERAL_CONVERSION_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


#define FCPPT_CHECK_LITERAL_CONVERSION(\
	dest,\
	source\
)\
static_assert(\
	!std::is_same<\
		source,\
		bool\
	>::value \
	&& \
	!(\
		std::is_integral<\
			dest\
		>::value \
		&& \
		std::is_floating_point<\
			source\
		>::value\
	),\
	"A literal conversion from bool, or from floating point to int is not allowed!"\
)

#endif
