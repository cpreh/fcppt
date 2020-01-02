//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_DETAIL_INIT_STORAGE_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_DETAIL_INIT_STORAGE_HPP_INCLUDED

#include <fcppt/use.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/container/array/init.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/checked_access.hpp>
#include <fcppt/math/matrix/row_type.hpp>
#include <fcppt/math/matrix/detail/index_absolute.hpp>
#include <fcppt/math/matrix/detail/static_storage.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <cstddef>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{
namespace detail
{

template<
	typename Type,
	fcppt::math::size_type C,
	std::size_t R
>
inline
fcppt::math::matrix::detail::static_storage<
	Type,
	fcppt::cast::size<
		fcppt::math::size_type
	>(
		R
	),
	C
>
init_storage(
	std::array<
		fcppt::math::matrix::row_type<
			Type,
			C
		>,
		R
	> const &_value
)
{
	typedef
	fcppt::math::matrix::detail::static_storage<
		Type,
		fcppt::cast::size<
			fcppt::math::size_type
		>(
			R
		),
		C
	>
	result_type;

	return
		result_type{
			fcppt::container::array::init<
				typename
				result_type::array_type
			>(
				[
					&_value
				](
					auto const _index
				)
				{
					FCPPT_USE(
						_index
					);

					typedef
					fcppt::math::matrix::detail::index_absolute<
						C,
						fcppt::cast::size<
							fcppt::math::size_type
						>(
							_index()
						)
					>
					index;

					return
						fcppt::math::detail::checked_access<
							index::column()
						>(
							std::get<
								index::row()
							>(
								_value
							)
						);
				}
			)
		};
}

}
}
}
}

#endif
