//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CAST_ENUM_TO_INT_HPP_INCLUDED
#define FCPPT_CAST_ENUM_TO_INT_HPP_INCLUDED

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
\brief Converts an enum to an int

\ingroup fcpptcasts

Converts \a _enum to the integer type specified by \a Dest. This cast is unsafe
and should only be used if the enum value can be converted to the destination
integers. Consider fcppt::casts::enum_to_underlying instead.
*/
template<
	typename Dest,
	typename Enum
>
inline
constexpr
typename
boost::enable_if<
	boost::mpl::and_<
		std::is_integral<
			Dest
		>,
		std::is_enum<
			Enum
		>
	>,
	Dest
>::type
enum_to_int(
	Enum const _enum
)
{
	return
		static_cast<
			Dest
		>(
			_enum
		);
}

}
}

#endif
