//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_ENUM_ARRAY_FOLD_HPP_INCLUDED
#define FCPPT_ALGORITHM_ENUM_ARRAY_FOLD_HPP_INCLUDED

#include <fcppt/algorithm/array_fold.hpp>
#include <fcppt/cast/int_to_enum.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\ingroup fcpptenum

\see fcppt::algorithm::array_fold
*/
template<
	typename Array,
	typename Function
>
inline
Array
enum_array_fold(
	Function const &_function
)
{
	return
		Array{
			fcppt::algorithm::array_fold<
				typename
				Array::internal
			>(
				[
					&_function
				](
					std::size_t const _index
				)
				{
					return
						_function(
							fcppt::cast::int_to_enum<
								typename Array::enum_type
							>(
								_index
							)
						);
				}
			)
		};
}

}
}

#endif
