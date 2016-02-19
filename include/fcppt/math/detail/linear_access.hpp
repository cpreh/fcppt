//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_LINEAR_ACCESS_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_LINEAR_ACCESS_HPP_INCLUDED

#include <fcppt/cast/to_signed.hpp>
#include <fcppt/container/to_value_type.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/storage_size.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace detail
{

template<
	fcppt::math::size_type Index,
	typename Storage
>
inline
fcppt::container::to_value_type<
	Storage
> &
linear_access(
	Storage &_storage
)
{
	static_assert(
		Index
		<
		fcppt::math::detail::storage_size<
			typename
			std::remove_const<
				Storage
			>::type
		>::value,
		"linear_access out of range"
	);

	return
		*(
			_storage.begin()
			+
			fcppt::cast::to_signed(
				Index
			)
		);
}

}
}
}

#endif
