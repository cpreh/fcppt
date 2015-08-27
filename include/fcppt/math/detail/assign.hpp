//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_ASSIGN_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_ASSIGN_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename Dest,
	typename Src
>
inline
Dest &
assign(
	Dest &_dest,
	Src const &_src
)
{
	auto const &src_storage(
		_src.storage()
	);

	std::copy(
		src_storage.begin(),
		src_storage.end(),
		_dest.storage().begin()
	);

	return
		_dest;
}

}
}
}

#endif
