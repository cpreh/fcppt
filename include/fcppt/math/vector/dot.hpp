//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_DOT_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_DOT_HPP_INCLUDED

#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/exception.hpp>
#include <fcppt/text.hpp>

namespace fcppt
{
namespace math
{
namespace vector
{

template<
	typename T,
	typename N,
	typename S
>
typename basic<T, N, S>::value_type
dot(
	basic<T, N, S> const &l,
	basic<T, N, S> const &r
)
{
	if(l.size() != r.size())
		throw exception(
			FCPPT_TEXT("Dimensions of vectors do not match in dot()!"));

	T result(static_cast<T>(0));

	for(typename basic<T, N, S>::size_type i = 0; i < l.size(); ++i)
		result += l[i] * r[i];

	return result;
}

}
}
}

#endif
