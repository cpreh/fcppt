//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_NORMAL_STORAGE_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_NORMAL_STORAGE_HPP_INCLUDED

#include <fcppt/math/detail/simple_normal_storage.hpp>
#include <fcppt/restrict_typedef_struct.hpp>

namespace fcppt
{
namespace math
{
namespace vector
{

template<
	typename T,
	typename N
>
struct normal_storage
:
math::detail::simple_normal_storage<
	T,
	N
>
{
	FCPPT_RESTRICT_TYPEDEF_STRUCT(
		normal_storage
	);
};

}
}
}

#endif
