//          Copyright Carl Philipp Reh 2009 - 2013.
//          Copyright Philipp Middendorf 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_ARRAY_FOLD_STATIC_HPP_INCLUDED
#define FCPPT_ALGORITHM_ARRAY_FOLD_STATIC_HPP_INCLUDED

#include <fcppt/algorithm/detail/array_fold_static.hpp>
#include <fcppt/container/array_size.hpp>
#include <fcppt/type_traits/is_std_array.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief Constructs an array from a function object with static indices

\ingroup fcpptalgorithm

Constructs an array of type \a Array by calling <code>_function<Index></code>
for every index.

\tparam Array Must be a std::array

\tparam Function Must be a function callable with
<code>_function<Index>()</code>, returning elements of type <code>typename
Array::value_type</code>

\param _function The function to use for initialization
*/
template<
	typename Array,
	typename Function
>
typename boost::enable_if<
	fcppt::type_traits::is_std_array<
		Array
	>,
	Array
>::type
array_fold_static(
	Function const &_function
)
{
	return
		fcppt::algorithm::detail::array_fold_static<
			0u,
			typename Array::value_type,
			fcppt::container::array_size<
				Array
			>::value
		>(
			_function
		);
}

}
}

#endif
