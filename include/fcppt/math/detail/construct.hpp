//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_CONSTRUCT_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_CONSTRUCT_HPP_INCLUDED

#include <fcppt/no_init.hpp>


namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename Dest,
	typename Src
>
Dest const
construct(
	Src const &src,
	typename Src::value_type const &value
)
{
	Dest ret{
		fcppt::no_init()
	};

	for(
		typename Src::size_type i = 0;
		i < src.size();
		++i
	)
		ret[i] = src[i];

	ret[
		Src::dim_wrapper::value
	] = value;

	return ret;
}

}
}
}

#endif
