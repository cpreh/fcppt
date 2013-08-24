//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CAST_ENUM_TO_UNDERLYING_HPP_INCLUDED
#define FCPPT_CAST_ENUM_TO_UNDERLYING_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace cast
{

template<
	typename Enum
>
inline
constexpr
typename
boost::enable_if<
	std::is_enum<
		Enum
	>,
	typename
	std::underlying_type<
		Enum
	>::type
>::type
enum_to_underlying(
	Enum const _enum
)
{
	return
		static_cast<
			typename
			std::underlying_type<
				Enum
			>::type
		>(
			_enum
		);
}

}
}

#endif
