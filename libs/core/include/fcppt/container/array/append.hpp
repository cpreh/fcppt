//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_ARRAY_APPEND_HPP_INCLUDED
#define FCPPT_CONTAINER_ARRAY_APPEND_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/container/array/init.hpp>
#include <fcppt/container/array/size.hpp>
#include <fcppt/type_traits/is_std_array.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/type_traits/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace array
{

/**
\brief Appends two arrays.

\ingroup fcpptcontainerarray

Let <code>_array1 = [x_1, ..., x_n]</code>
and <code>_array2 = [y_1, ..., y_m]</code>.
The result is <code>[x_1, ..., x_n, y_1, ..., y_m]</code>.

Both arrays must have the same value type.

\tparam Array1 Must be a std::array

\tparam Array2 Must be a std::array
*/
template<
	typename Array1,
	typename Array2
>
std::array<
	fcppt::type_traits::value_type<
		fcppt::type_traits::remove_cv_ref_t<
			Array1
		>
	>,
	fcppt::container::array::size<
		fcppt::type_traits::remove_cv_ref_t<
			Array1
		>
	>::value
	+
	fcppt::container::array::size<
		fcppt::type_traits::remove_cv_ref_t<
			Array2
		>
	>::value
>
append(
	Array1 &&_array1,
	Array2 &&_array2
)
{
	typedef
	fcppt::type_traits::remove_cv_ref_t<
		Array1
	>
	array1;

	typedef
	fcppt::type_traits::remove_cv_ref_t<
		Array2
	>
	array2;

	typedef
	fcppt::type_traits::value_type<
		array1
	>
	element_type;

	static_assert(
		fcppt::type_traits::is_std_array<
			array1
		>::value
	);

	static_assert(
		fcppt::type_traits::is_std_array<
			array2
		>::value
	);

	static_assert(
		std::is_same_v<
			element_type,
			fcppt::type_traits::value_type<
				array2
			>
		>
	);

	typedef
	fcppt::container::array::size<
		Array1
	>
	array1_size;

	return
		fcppt::container::array::init<
			std::array<
				element_type,
				array1_size::value
				+
				fcppt::container::array::size<
					array2
				>::value
			>
		>(
			[
				&_array1,
				&_array2
			](
				auto const _index
			)
			{
				if constexpr(
					_index()
					<
					array1_size::value
				)
					return
						fcppt::move_if_rvalue<
							Array1
						>(
							std::get<
								_index()
							>(
								_array1
							)
						);
				else
					return
						fcppt::move_if_rvalue<
							Array2
						>(
							std::get<
								_index()
								-
								array1_size::value
							>(
								_array2
							)
						);
			}
		);

}

}
}
}

#endif
