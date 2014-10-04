//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_ENUM_ARRAY_FOLD_STATIC_HPP_INCLUDED
#define FCPPT_ALGORITHM_ENUM_ARRAY_FOLD_STATIC_HPP_INCLUDED

#include <fcppt/algorithm/array_fold_static.hpp>
#include <fcppt/algorithm/detail/enum_array_fold_static_function.hpp>


namespace fcppt
{
namespace algorithm
{

template<
	typename Array,
	typename Function
>
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
				fcppt::algorithm::detail::enum_array_fold_static_function<
					Array,
					Function
				>(
					_function
				)
			)
		};
}

}
}

#endif
