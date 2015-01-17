//          Copyright Carl Philipp Reh 2009 - 2015.
//          Copyright Philipp Middendorf 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_PROJECT_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_PROJECT_HPP_INCLUDED

#include <fcppt/math/vector/dot.hpp>

namespace fcppt
{
namespace math
{
namespace vector
{
/**
\brief Project a vector orthogonally onto another vector
\ingroup fcpptmathvector
\tparam Vector A fcppt::math::vector::object type.
\param u The vector to project to
\param v The vector to project from

This is expressed as \f[ \textrm{project}(u,v) = \frac{\langle u,v \rangle}{\langle u,u \rangle} u \f]

See:

http://en.wikipedia.org/wiki/Gram_schmidt#The_Gram.E2.80.93Schmidt_process

for an explanation.

\see fcppt::math::vector::orthogonalize
*/
template<typename Vector>
Vector const
project(
	Vector const &u,
	Vector const &v)
{
	return fcppt::math::vector::dot(v,u)/fcppt::math::vector::dot(u,u) * u;
}
}
}
}

#endif
