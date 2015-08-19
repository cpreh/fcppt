//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_INIT_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_INIT_HPP_INCLUDED

#include <fcppt/algorithm/array_fold.hpp>
#include <fcppt/math/detail/init_function.hpp>


namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename Result,
	typename Function
>
inline
Result
init(
	Function const &_function
)
{
	return
		Result(
			fcppt::algorithm::array_fold<
				typename
				Result::storage_type
			>(
				fcppt::math::detail::init_function<
					typename
					Result::size_type,
					Function
				>(
					_function
				)
			)
		);
}

}
}
}

#endif
