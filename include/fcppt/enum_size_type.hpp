//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ENUM_SIZE_TYPE_HPP_INCLUDED
#define FCPPT_ENUM_SIZE_TYPE_HPP_INCLUDED

#include <fcppt/enum_size_type_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief The size type used to count the number of enumerators in an enum

\ingroup fcpptenum

The size type used to count the number of enumerators in \a Type.

\tparam Type Must be an enum type
*/
template<
	typename Type
>
struct enum_size_type
{
	static_assert(
		std::is_enum<
			Type
		>::value,
		"Type must be an enum type"
	);

	typedef
	typename
	std::make_unsigned<
		typename
		std::underlying_type<
			Type
		>::type
	>::type
	type;
};

}

#endif
