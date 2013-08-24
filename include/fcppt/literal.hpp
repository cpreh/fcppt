//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LITERAL_HPP_INCLUDED
#define FCPPT_LITERAL_HPP_INCLUDED

#include <fcppt/make_literal_fundamental.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Creates a literal of a type

\ingroup fcpptvarious

Creates a literal of type \a Type from the value \a _integral

\tparam Type The literal type to create

\tparam Fundamental A fundamental type
*/
template<
	typename Type,
	typename Fundamental
>
constexpr
typename
boost::enable_if<
	std::is_fundamental<
		Fundamental
	>,
	Type
>::type
literal(
	Fundamental const _integral
)
{
	return
		fcppt::make_literal<
			Type
		>::get(
			_integral
		);
}

}

#endif
