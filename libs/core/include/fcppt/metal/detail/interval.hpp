//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_METAL_DETAIL_INTERVAL_HPP_INCLUDED
#define FCPPT_METAL_DETAIL_INTERVAL_HPP_INCLUDED

#include <fcppt/metal/from_number_list.hpp>
#include <fcppt/metal/to_number.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace metal
{
namespace detail
{

template<
	typename Type,
	Type Begin,
	Type End
>
struct interval
{
	static_assert(
		std::is_integral_v<
			Type
		>
	);

	static_assert(
		Begin
		<=
		End
	);

	typedef
	fcppt::metal::from_number_list<
		Type,
		::metal::iota<
			fcppt::metal::to_number<
				std::integral_constant<
					Type,
					Begin
				>
			>,
			fcppt::metal::to_number<
				std::integral_constant<
					Type,
					End
					-
					Begin
				>
			>
		>
	>
	type;
};

}
}
}

#endif
