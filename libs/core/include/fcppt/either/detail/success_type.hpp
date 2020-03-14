//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_EITHER_DETAIL_SUCCESS_TYPE_HPP_INCLUDED
#define FCPPT_EITHER_DETAIL_SUCCESS_TYPE_HPP_INCLUDED

#include <fcppt/either/is_object.hpp>


namespace fcppt
{
namespace either
{
namespace detail
{

template<
	typename Either
>
struct success_type
{
	static_assert(
		fcppt::either::is_object<
			Either
		>::value,
		"Either must be an either"
	);

	using
	type
	=
	typename
	Either::success;
};

}
}
}

#endif
