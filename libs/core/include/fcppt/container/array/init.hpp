//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_ARRAY_INIT_HPP_INCLUDED
#define FCPPT_CONTAINER_ARRAY_INIT_HPP_INCLUDED

#include <fcppt/container/array/size.hpp>
#include <fcppt/container/array/detail/init.hpp>
#include <fcppt/type_traits/is_std_array.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace array
{

/**
\brief Constructs an array by calling a function with static indices.

\ingroup fcpptcontainerarray

Constructs an array of type \a Array by calling
<code>_function(std::integral_constant<std::size_t, Index>)</code> for every
index.

\tparam Array Must be a <code>std::array</code>.

\tparam Function Must be a function callable as <code>Array::value_type
(std::integral_constant<std::size_t, I>)</code>.
*/
template<
	typename Array,
	typename Function
>
inline
Array
init(
	Function const &_function
)
{
	static_assert(
		fcppt::type_traits::is_std_array<
			Array
		>::value,
		"Array must be an array"
	);

	return
		fcppt::container::array::detail::init<
			Array
		>(
			std::make_index_sequence<
				fcppt::container::array::size<
					Array
				>::value
			>{},
			_function
		);
}

}
}
}

#endif
