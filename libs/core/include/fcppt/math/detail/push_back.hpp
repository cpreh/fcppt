//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_PUSH_BACK_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_PUSH_BACK_HPP_INCLUDED

#include <fcppt/use.hpp>
#include <fcppt/container/array_init.hpp>
#include <fcppt/container/array_push_back.hpp>
#include <fcppt/math/from_array.hpp>
#include <fcppt/math/detail/assert_static_storage.hpp>
#include <fcppt/math/detail/checked_access.hpp>
#include <fcppt/math/detail/static_storage_impl.hpp>
#include <fcppt/type_traits/value_type.hpp>


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
Dest
push_back(
	Src const &_src,
	fcppt::type_traits::value_type<
		Src
	> const &_value
)
{
	static_assert(
		Dest::static_size::value
		==
		Src::static_size::value
		+
		1u,
		""
	);

	FCPPT_MATH_DETAIL_ASSERT_STATIC_STORAGE(
		typename
		Dest::storage_type
	);

	typedef
	fcppt::math::detail::static_storage<
		fcppt::type_traits::value_type<
			Src
		>,
		Src::static_size::value
	>
	src_storage;

	return
		fcppt::math::from_array<
			Dest
		>(
			fcppt::container::array_push_back(
				fcppt::container::array_init<
					typename
					src_storage::array_type
				>(
					[
						&_src
					](
						auto const _index
					)
					{
						FCPPT_USE(
							_index
						);

						return
							fcppt::math::detail::checked_access<
								_index()
							>(
								_src
							);
					}
				),
				_value
			)
		);
}

}
}
}

#endif
