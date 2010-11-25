#ifndef FCPPT_MATH_VECTOR_ORTHOGONALIZE_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_ORTHOGONALIZE_HPP_INCLUDED

#include "project.hpp"
#include <boost/spirit/home/phoenix/core/argument.hpp>
#include <boost/spirit/home/phoenix/operator/arithmetic.hpp>
#include <boost/spirit/home/phoenix/bind/bind_function.hpp>
#include <numeric>

namespace fcppt
{
namespace math
{
namespace vector
{
template<typename Container>
Container const
orthogonalize(
	Container const &input)
{
	typedef typename
	Container::value_type
	vector;
	
	Container result;
	for (typename Container::const_iterator i = input.begin(); i != input.end(); ++i)
		result.push_back(
			::std::accumulate(
				result.begin(),
				result.end(),
				*i,
				boost::phoenix::arg_names::arg1 - 
				boost::phoenix::bind(
					&fcppt::math::vector::project<vector>,
					boost::phoenix::arg_names::arg2,
					boost::phoenix::arg_names::arg1)));
	return result;
}
}
}
}

#endif
