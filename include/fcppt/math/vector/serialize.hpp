//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_SERIALIZE_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_SERIALIZE_HPP_INCLUDED

#include <fcppt/math/vector/basic_impl.hpp>

namespace fcppt
{
namespace math
{
namespace vector
{

template<
	typename T,
	typename N,
	typename S,
	typename Archive
>
void serialize(
	Archive &ar,
	basic<T, N, S> &v,
	unsigned)
{
	for (typename basic<T, N, S>::size_type i = 0; i < v.size(); ++i)
		ar & v[i];
}

}
}
}

#endif
