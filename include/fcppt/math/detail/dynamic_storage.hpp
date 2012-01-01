//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_DYNAMIC_STORAGE_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_DYNAMIC_STORAGE_HPP_INCLUDED

#include <fcppt/container/raw_vector_fwd.hpp>

namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename T
>
struct dynamic_storage
{
	typedef container::raw_vector<
		T
	> type;
};

}
}
}

#endif
