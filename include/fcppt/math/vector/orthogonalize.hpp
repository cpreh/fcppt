//          Copyright Carl Philipp Reh 2009 - 2012.
//          Copyright Philipp Middendorf 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_ORTHOGONALIZE_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_ORTHOGONALIZE_HPP_INCLUDED

#include "project.hpp"
#include <fcppt/config/external_begin.hpp>
#include <boost/spirit/home/phoenix/bind/bind_function.hpp>
#include <boost/spirit/home/phoenix/core/argument.hpp>
#include <boost/spirit/home/phoenix/operator/arithmetic.hpp>
#include <iterator>
#include <numeric>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace vector
{
/**
\brief Orthogonalizes a sequence of vectors
\ingroup fcpptmathvector
\tparam Iterator A non-const forward-iterator pointing to a fcppt::math::vector::object
\tparam Iterator A non-const forward-iterator pointing to a fcppt::math::vector::object
\param begin The beginning of the sequence to orthogonalize
\param end One past the end of the sequence to orthogonalize

This uses the modified Gram-Schmidt (MGS) orthogonalization instead of the
classical Gram-Schmidt for numerical stability. See

http://en.wikipedia.org/wiki/Gram_schmidt#Numerical_stability

For more information on the process.

\note
The sequence is modified in-place.

\note
No normalization takes place. Use fcppt::math::vector::normalize for
that.

Example:

\code
typedef
fcppt::math::vector::static_<float,2>::type
vec2f;

typedef
std::vector<vec2f>
vector_sequence;

vector_sequence vectors;
// Point to the right
vectors.push_back(
	vec2f(1.0f,0.0f));
// Point a little upward
vectors.push_back(
	vec2f(1.0f,0.5f));

fcppt::math::vector::orthogonalize(
	vectors.begin(),
	vectors.end());

std::cout << vectors[0] << "\n";
std::cout << vectors[1] << "\n";
\endcode

\see fcppt::math::vector::project
*/
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
