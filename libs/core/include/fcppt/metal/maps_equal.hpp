//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_METAL_MAPS_EQUAL_HPP_INCLUDED
#define FCPPT_METAL_MAPS_EQUAL_HPP_INCLUDED

#include <fcppt/metal/detail/map_same_values.hpp>
#include <fcppt/metal/set/from_list_relaxed.hpp>
#include <fcppt/metal/set/make.hpp>
#include <fcppt/metal/set/symmetric_difference.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal/lambda/always.hpp>
#include <metal/lambda/bind.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/map/keys.hpp>
#include <metal/number/if.hpp>
#include <metal/number/number.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace metal
{

template<
	typename Map1,
	typename Map2
>
using
maps_equal
=
::metal::invoke<
	::metal::if_<
		::metal::as_number<
			std::is_same<
				fcppt::metal::set::symmetric_difference<
					fcppt::metal::set::from_list_relaxed<
						::metal::keys<
							Map1
						>
					>,
					fcppt::metal::set::from_list_relaxed<
						::metal::keys<
							Map2
						>
					>
				>,
				fcppt::metal::set::make<>
			>
		>,
		::metal::bind<
			::metal::lambda<
				fcppt::metal::detail::map_same_values
			>,
			::metal::always<
				Map1
			>,
			::metal::always<
				Map2
			>
		>,
		::metal::always<
			::metal::false_
		>
	>
>;

}
}

#endif
