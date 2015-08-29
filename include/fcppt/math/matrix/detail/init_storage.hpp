//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_DETAIL_INIT_STORAGE_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_DETAIL_INIT_STORAGE_HPP_INCLUDED

#include <fcppt/algorithm/array_fold_static.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/math/matrix/row_type.hpp>
#include <fcppt/math/matrix/detail/index_absolute.hpp>
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
	typename Storage,
	typename Type,
	std::size_t C,
	std::size_t R
>
inline
// TODO: Use matrix::static_storage here
Storage
init_storage(
	std::array<
		std::array<
			Type,
			C
		>,
		R
	> const &_value
)
{
	return
		fcppt::algorithm::array_fold_static<
			Storage
		>(
			[
				&_value
			](
				auto const _index
			)
			{
				typedef
				fcppt::math::matrix::detail::index_absolute<
					fcppt::cast::size<
						fcppt::math::size_type
					>(
						C
					),
					fcppt::cast::size<
						fcppt::math::size_type
					>(
						_index()
					)
				>
				index;

				return
					std::get<
						index::column()
					>(
						std::get<
							index::row()
						>(
							_value
						)
					);
			}
		);
}

}
}
}
}

#endif
