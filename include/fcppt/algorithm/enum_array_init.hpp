//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_ENUM_ARRAY_INIT_HPP_INCLUDED
#define FCPPT_ALGORITHM_ENUM_ARRAY_INIT_HPP_INCLUDED

#include <fcppt/use.hpp>
#include <fcppt/algorithm/array_init.hpp>
#include <fcppt/cast/int_to_enum_fun.hpp>
#include <fcppt/mpl/integral_cast.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\ingroup fcpptenum

\see fcppt::algorithm::array_init
*/
template<
	typename Array,
	typename Function
>
inline
Array
enum_array_init(
	Function const &_function
)
{
	return
		Array{
			fcppt::algorithm::array_init<
				typename
				Array::internal
			>(
				[
					&_function
				](
					auto const _fcppt_index
				)
				{
					FCPPT_USE(
						_fcppt_index
					);

					return
						_function(
							fcppt::mpl::integral_cast<
								typename
								Array::enum_type,
								fcppt::cast::int_to_enum_fun,
								decltype(
									_fcppt_index
								)
							>{}
						);
				}
			)
		};
}

}
}

#endif
