//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_ARRAY_INIT_MOVE_HPP_INCLUDED
#define FCPPT_CONTAINER_ARRAY_INIT_MOVE_HPP_INCLUDED

#include <fcppt/use.hpp>
#include <fcppt/container/array/init.hpp>
#include <fcppt/type_traits/is_std_array.hpp>


namespace fcppt
{
namespace container
{
namespace array
{

/**
\brief Constructs an array by calling a function for every element.

\ingroup fcpptcontainerarray

Constructs an array of type \a Array by initializing every element with
<code>_function()</code>.

\tparam Array Must be a <code>std::array</code>.

\tparam Function A function callable as <code>Array::value_type ()</code>.
*/
template<
	typename Array,
	typename Function
>
inline
Array
init_move(
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
		fcppt::container::array::init<
			Array
		>(
			[
				&_function
			](
				auto const _index
			)
			{
				FCPPT_USE(
					_index
				);

				return
					_function();
			}
		);
}

}
}
}

#endif
