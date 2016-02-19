//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_ARRAY_INIT_HPP_INCLUDED
#define FCPPT_ALGORITHM_ARRAY_INIT_HPP_INCLUDED

#include <fcppt/tag_value.hpp>
#include <fcppt/algorithm/vararg_map.hpp>
#include <fcppt/container/array_size.hpp>
#include <fcppt/type_traits/is_std_array.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/range_c.hpp>
#include <cstddef>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief Constructs an array from a function object with static indices

\ingroup fcpptalgorithm

Constructs an array of type \a Array by calling
<code>_function(std::integral_constant<std::size_t, Index>)</code> for every
index.

\tparam Array Must be a std::array

\tparam Function Must be a function callable as <code>Array::value_type
(std::integral_constant<std::size_t, I>)</code>.
*/
template<
	typename Array,
	typename Function
>
inline
Array
array_init(
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
		fcppt::algorithm::vararg_map<
			boost::mpl::range_c<
				std::size_t,
				0,
				fcppt::container::array_size<
					Array
				>::value
			>
		>(
			[](
				auto &&... _args_array
			)
			{
				return
					Array{{
						std::forward<
							decltype(
								_args_array
							)
						>(
							_args_array
						)...
					}};
			},
			[
				&_function
			](
				auto const _tag
			)
			{
				return
					_function(
						std::integral_constant<
							std::size_t,
							fcppt::tag_value(
								_tag
							).value
						>{}
					);
			}
		);
}

}
}

#endif
