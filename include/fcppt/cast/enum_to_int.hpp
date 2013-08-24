//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CAST_ENUM_TO_INT_HPP_INCLUDED
#define FCPPT_CAST_ENUM_TO_INT_HPP_INCLUDED

#include <fcppt/type_traits/is_enum.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/and.hpp>
#include <boost/utility/enable_if.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace cast
{

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
		fcppt::type_traits::is_enum<
			Enum
		>
	>,
	Dest
>::type
enum_to_int(
	Enum const &_enum
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
