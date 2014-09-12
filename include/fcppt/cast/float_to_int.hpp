//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CAST_FLOAT_TO_INT_HPP_INCLUDED
#define FCPPT_CAST_FLOAT_TO_INT_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/and.hpp>
#include <boost/utility/enable_if.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace cast
{

/**
\brief Converts a float to a signed int

\ingroup fcpptcasts

Converts \a _source to an integer. The type signature ensures that only signed
integers can be used a destination. If you need to cast to unsigned integers,
use fcppt::casts::to_unsigned in addition. This cast is unsafe and should be
used with care.
*/
template<
	typename Dest,
	typename Source
>
inline
typename
boost::enable_if<
	boost::mpl::and_<
		std::is_floating_point<
			Source
		>,
		std::is_signed<
			Dest
		>
	>,
	Dest
>::type
float_to_int(
	Source const _source
)
{
	return
		static_cast<
			Dest
		>(
			_source
		);
}

}
}

#endif
