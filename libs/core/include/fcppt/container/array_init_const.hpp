//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_ARRAY_INIT_CONST_HPP_INCLUDED
#define FCPPT_CONTAINER_ARRAY_INIT_CONST_HPP_INCLUDED

#include <fcppt/cast/to_void.hpp>
#include <fcppt/container/array_init.hpp>
#include <fcppt/type_traits/value_type.hpp>
#include <fcppt/type_traits/is_std_array.hpp>


namespace fcppt
{
namespace container
{

/**
\brief Constructs an array from a value.

\ingroup fcpptcontainer

Constructs an array of type \a Array by initializing every element with \a
_value.

\tparam Array Must be a <code>std::array</code>.
*/
template<
	typename Array
>
inline
Array
array_init_const(
	fcppt::type_traits::value_type<
		Array
	> const &_value
)
{
	static_assert(
		fcppt::type_traits::is_std_array<
			Array
		>::value,
		"Array must be an array"
	);

	return
		fcppt::container::array_init<
			Array
		>(
			[
				&_value
			](
				auto const _index
			)
			{
				fcppt::cast::to_void(
					_index
				);

				return
					_value;
			}
		);
}

}
}

#endif
