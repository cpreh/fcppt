//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_DETAIL_INIT_STORAGE_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_DETAIL_INIT_STORAGE_HPP_INCLUDED

#include <fcppt/algorithm/array_fold.hpp>
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
		fcppt::algorithm::array_fold<
			Storage
		>(
			[
				&_value
			](
				std::size_t const _index
			)
			{
				auto const index(
					fcppt::math::matrix::detail::index_absolute<
						std::size_t,
						C
					>(
						_index
					)
				);

				return
					_value[
						index.row()
					][
						index.column()
					];
			}
		);
}

}
}
}
}

#endif
