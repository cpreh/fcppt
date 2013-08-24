//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CAST_TO_UNSIGNED_HPP_INCLUDED
#define FCPPT_CAST_TO_UNSIGNED_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace cast
{

template<
	typename Type
>
inline
constexpr
typename
boost::enable_if<
	std::is_signed<
		Type
	>,
	typename
	std::make_unsigned<
		Type
	>::type
>::type
to_unsigned(
	Type const _value
)
{
	return
		static_cast<
			typename
			std::make_unsigned<
				Type
			>::type
		>(
			_value
		);
}

}
}

#endif
