//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_DYNAMIC_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_DYNAMIC_HPP_INCLUDED

#include <fcppt/container/raw_vector_decl.hpp>
#include <fcppt/math/detail/dynamic_size.hpp>
#include <fcppt/math/detail/dynamic_storage.hpp>
#include <fcppt/math/vector/object_fwd.hpp>


namespace fcppt
{
namespace math
{
namespace vector
{

/**
\brief Typedef helper for dynamic vectors
\tparam The vector's <code>value_type</code>
\ingroup fcpptmathvector
See the introduction to fcppt::math::vector::object for more information on
dynamic vectors (and on this class).
*/
template<
	typename T
>
struct dynamic
{
	typedef object<
		T,
		math::detail::dynamic_size,
		typename math::detail::dynamic_storage<
			T
		>::type
	> type;
};

}
}
}

#endif
