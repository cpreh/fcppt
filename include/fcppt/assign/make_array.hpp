//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSIGN_MAKE_ARRAY_HPP_INCLUDED
#define FCPPT_ASSIGN_MAKE_ARRAY_HPP_INCLUDED

#include <fcppt/assign/detail/array_impl.hpp>

namespace fcppt
{
namespace assign
{

template<
	typename T
>
detail::array<T,1>
make_array(
	T const &t
)
{
	return detail::array<T,1>(
		t
	);
}

}
}

#endif
