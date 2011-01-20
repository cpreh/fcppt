//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_STATIC_STORAGE_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_STATIC_STORAGE_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/container/array.hpp>
#include <fcppt/restrict_typedef_struct.hpp>

namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename T,
	size_type N
>
struct static_storage
{
	typedef fcppt::container::array<
		T,
		N
	> type;

	FCPPT_RESTRICT_TYPEDEF_STRUCT(static_storage)
};

}
}
}

#endif
