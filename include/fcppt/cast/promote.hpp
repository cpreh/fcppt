//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CAST_PROMOTE_HPP_INCLUDED
#define FCPPT_CAST_PROMOTE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/type_traits/promote.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace cast
{

/**
\brief Casts a type to its promoted type

\ingroup fcpptcasts

Converts \a _value to its promoted type. This can be used if explicit promotion
is desired (e.g. when outputting to an ostream).

\tparam Type Must be a fundamental type
*/
template<
	typename Type
>
inline
constexpr
typename
boost::promote<
	Type
>::type
promote(
	Type const _value
)
{
	static_assert(
		std::is_fundamental<
			Type
		>,
		"promote can only promote fundamental types"
	);

	return
		static_cast<
			typename
			boost::promote<
				Type
			>::type
		>(
			_value
		);
}

}
}

#endif
