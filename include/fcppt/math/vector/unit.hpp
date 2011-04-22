//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_UNIT_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_UNIT_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <boost/utility/enable_if.hpp>

namespace fcppt
{
namespace math
{
namespace vector
{

/// Creates a vector of type \tparam Vec with all components set to 0 expect for component \tparam N which is set to 1
template<
	typename Vec,
	fcppt::math::size_type N
>
typename boost::enable_if_c<
	(
		Vec::dim_wrapper::value
		>
		N
	),
	Vec
>::type const
unit()
{
	Vec ret;

	for(
		typename Vec::size_type index = 0;
		index < Vec::dim_wrapper::value;
		++index
	)
		ret[
			index
		] =
			static_cast<
				typename Vec::value_type
			>(
				index == N
				?
					1
				:
					0
			);
	return ret;
}

}
}
}

#endif
