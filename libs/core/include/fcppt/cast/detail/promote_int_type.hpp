//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CAST_DETAIL_PROMOTE_INT_TYPE_HPP_INCLUDED
#define FCPPT_CAST_DETAIL_PROMOTE_INT_TYPE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace cast
{
namespace detail
{

template<
	typename Type
>
struct promote_int_type
{
	static_assert(
		std::is_integral_v<
			Type
		>,
		"Type must be an integral type."
	);

	using
	type
	=
	decltype(
		+std::declval<
			Type
		>()
	);
};

}
}
}

#endif
