//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_INIT_FUNCTION_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_INIT_FUNCTION_HPP_INCLUDED

#include <fcppt/nonassignable.hpp>
#include <fcppt/cast/size_fun.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/mpl/integral_cast.hpp>


namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename Function
>
class init_function
{
	FCPPT_NONASSIGNABLE(
		init_function
	);
public:
	explicit
	init_function(
		Function const &_function
	)
	:
		function_(
			_function
		)
	{
	}

	template<
		typename T
	>
	decltype(
		auto
	)
	operator()(
		T
	) const
	{
		return
			function_(
				fcppt::mpl::integral_cast<
					fcppt::math::size_type,
					fcppt::cast::size_fun,
					T
				>{}
			);
	}
private:
	Function const function_;
};

}
}
}

#endif
