//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_METAL_DETAIL_MAP_SAME_VALUES_HPP_INCLUDED
#define FCPPT_METAL_DETAIL_MAP_SAME_VALUES_HPP_INCLUDED

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
	typename Map1,
	typename Map2
>
using
map_same_values
=
::metal::all_of<
	::metal::keys<
		Map1
	>,
	::metal::bind<
		::metal::trait<
			std::is_same
		>,
		::metal::bind<
			::metal::lambda<
				::metal::at_key
			>,
			::metal::always<
				Map1
			>,
			::metal::_1
		>,
		::metal::bind<
			::metal::lambda<
				::metal::at_key
			>,
			::metal::always<
				Map2
			>,
			::metal::_1
		>
	>
>;

}
}
}

#endif
