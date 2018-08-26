//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LITERAL_HPP_INCLUDED
#define FCPPT_LITERAL_HPP_INCLUDED

#include <fcppt/make_literal_fundamental.hpp>
#include <fcppt/type_traits/is_value.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Creates a literal of a type

\ingroup fcpptliteral

Creates a literal of type \a Type from the value \a _integral, using
fcppt::make_literal to do any conversions if necessary.

\tparam Type The literal type to create. Must be a value type. See \link fcppt::type_traits::is_value\endlink.

\tparam Arg An arithmetic type.
*/
template<
	typename Type,
	typename Arg
>
constexpr
typename
fcppt::make_literal<
	Type
>::decorated_type
literal(
	Arg const &&_integral
)
{
	static_assert(
		fcppt::type_traits::is_value<
			Type
		>::value,
		"Type must be a value type"
	);

	static_assert(
		std::is_arithmetic<
			Arg
		>::value,
		"literal can only be used on arithmetic types"
	);

	return
		fcppt::make_literal<
			Type
		>::get(
			_integral
		);
}

}

#endif
