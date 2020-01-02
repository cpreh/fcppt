//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_METAL_MAX_VALUE_HPP_INCLUDED
#define FCPPT_METAL_MAX_VALUE_HPP_INCLUDED

#include <fcppt/metal/from_number.hpp>
#include <fcppt/metal/to_number_list.hpp>
#include <fcppt/type_traits/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace metal
{

/**
\brief Calculates the maximum value in a sequence.

\ingroup fcpptmetal

Calculates the maximum value in \a Sequence.

\snippet metal/max_value.cpp metal_max_value

\tparam Sequence A non empty metal::list of std::integral_constants.
*/
template<
	typename Sequence
>
using
max_value
=
fcppt::metal::from_number<
	fcppt::type_traits::value_type<
		::metal::front<
			Sequence
		>
	>,
	::metal::accumulate<
		::metal::bind<
			::metal::lambda<
				::metal::if_
			>,
			::metal::bind<
				::metal::lambda<
					::metal::greater
				>,
				::metal::_1,
				::metal::_2
			>,
			::metal::_1,
			::metal::_2
		>,
		::metal::front<
			fcppt::metal::to_number_list<
				Sequence
			>
		>,
		fcppt::metal::to_number_list<
			Sequence
		>
	>
>;

}
}

#endif
