//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CAST_SAFE_NUMERIC_HPP_INCLUDED
#define FCPPT_CAST_SAFE_NUMERIC_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace cast
{

/**
\brief Safe numeric cast is a safer <code>static_cast</code> that forbids lossy conversions

\ingroup fcpptcasts

This cast converts one arithmetic type to another, where the size of the
destination type must be at least the size of the source type.

Furthermore, the conversion is only allowed if and only if one of the following
cases hold true:

<ul>

<li>Both types are the same type</li>

<li>Both types are integer types and both have the same signedness</li>

<li>Both types are floating point types</li>

</ul>

\tparam Dest The destination type of the conversion

\tparam Source The source type of the conversion
*/
template<
	typename Dest,
	typename Source
>
constexpr
Dest
safe_numeric(
	Source const &_source
)
noexcept
{
	static_assert(
		sizeof(
			Dest
		)
		>=
		sizeof(
			Source
		)
		&&
		(
			std::is_same<
				Dest,
				Source
			>::value
			||
			(
				std::is_floating_point<
					Dest
				>::value
				&&
				std::is_floating_point<
					Source
				>::value
			)
			||
			(
				std::is_integral<
					Dest
				>::value
				&&
				std::is_integral<
					Source
				>::value
				&&
				std::is_signed<
					Dest
				>::value
				==
				std::is_signed<
					Source
				>::value
			)
		),
		"safe_numeric requirements not met"
	);

	return
		_source;
}

}
}

#endif
