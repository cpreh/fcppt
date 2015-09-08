//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_ENUM_ARRAY_FOLD_STATIC_HPP_INCLUDED
#define FCPPT_ALGORITHM_ENUM_ARRAY_FOLD_STATIC_HPP_INCLUDED

#include <fcppt/decltype_sink.hpp>
#include <fcppt/algorithm/array_fold_static.hpp>
#include <fcppt/cast/int_to_enum_fun.hpp>
#include <fcppt/mpl/integral_cast.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\ingroup fcpptenum

\see fcppt::algorithm::array_fold_static
*/
template<
	typename Array,
	typename Function
>
inline
Array
enum_array_fold_static(
	Function const &_function
)
{
	return
		Array{
			fcppt::algorithm::array_fold_static<
				typename
				Array::internal
			>(
				[
					&_function
				](
					auto const _index
				)
				{
					return
						_function(
							fcppt::mpl::integral_cast<
								typename
								Array::enum_type,
								fcppt::cast::int_to_enum_fun,
								FCPPT_DECLTYPE_SINK(
									_index
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
