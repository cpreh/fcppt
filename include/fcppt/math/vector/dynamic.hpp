//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_DYNAMIC_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_DYNAMIC_HPP_INCLUDED

#include <fcppt/math/vector/basic_fwd.hpp>
#include <fcppt/math/detail/dynamic_size.hpp>
#include <fcppt/math/detail/dynamic_storage.hpp>
#include <fcppt/container/raw_vector_decl.hpp>
#include <fcppt/restrict_typedef_struct.hpp>

namespace fcppt
{
namespace math
{
namespace vector
{

template<
	typename T
>
struct dynamic {
	typedef basic<
		T,
		math::detail::dynamic_size,
		typename math::detail::dynamic_storage<
			T
		>::type
	> type;

	FCPPT_RESTRICT_TYPEDEF_STRUCT(dynamic)
};

}
}
}

#endif
