//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LITERAL_HPP_INCLUDED
#define FCPPT_LITERAL_HPP_INCLUDED

#include <fcppt/make_literal_fundamental.hpp>
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

\tparam Type The literal type to create

\tparam Fundamental A fundamental type
*/
template<
	typename Type,
	typename Fundamental
>
constexpr
typename
fcppt::make_literal<
	Type
>::decorated_type
literal(
	Fundamental const &&_integral
)
{
	static_assert(
		std::is_fundamental<
			Fundamental
		>::value,
		"literal can only be used on fundamental types"
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
