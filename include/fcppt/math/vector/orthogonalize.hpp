//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_ORTHOGONALIZE_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_ORTHOGONALIZE_HPP_INCLUDED

#include "project.hpp"
#include <boost/spirit/home/phoenix/core/argument.hpp>
#include <boost/spirit/home/phoenix/operator/arithmetic.hpp>
#include <boost/spirit/home/phoenix/bind/bind_function.hpp>
#include <iterator>
#include <numeric>

namespace fcppt
{
namespace math
{
namespace vector
{
template<typename Iterator,typename EndIterator>
void
orthogonalize(
	Iterator const begin,
	EndIterator const end)
{
	typedef typename
	std::iterator_traits<Iterator>::value_type
	vector;

	for(Iterator it = begin; it != end; ++it)
	{
		(*it) = 
			::std::accumulate(
				begin,
				it,
				*it,
				boost::phoenix::arg_names::arg1 - 
				boost::phoenix::bind(
					&fcppt::math::vector::project<vector>,
					boost::phoenix::arg_names::arg2,
					boost::phoenix::arg_names::arg1));
	}
}
}
}
}

#endif
