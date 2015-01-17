//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_STRUCTURE_CAST_FUN_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_STRUCTURE_CAST_FUN_HPP_INCLUDED

namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename T
>
struct structure_cast_fun
{
	typedef T result_type;

	template<
		typename U
	>
	T operator()(
		U const &u
	) const
	{
		return static_cast<T>(u);
	}
};

}
}
}

#endif
