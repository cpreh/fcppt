//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_ARRAY_JOIN_HPP_INCLUDED
#define FCPPT_CONTAINER_ARRAY_JOIN_HPP_INCLUDED

#include <fcppt/container/array/size.hpp>
#include <fcppt/container/array/detail/join.hpp>
#include <fcppt/metal/from_number.hpp>
#include <fcppt/metal/to_number.hpp>
#include <fcppt/type_traits/is_std_array.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/type_traits/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <cstddef>
#include <metal.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace array
{

/**
\brief Appends multiple arrays.

\ingroup fcpptcontainerarray

Let <code>a_1 = Array1</code> and <code>Arrays = a_2, ..., a_n</code>.
The result is equivalent to <code>append(a_1, ..., append(a_{n-1}, a_n) ...)</code>.

All arrays must have the same value type.

\tparam Array1 Must be a std::array

\tparam Arrays Must all be a std::array

\see fcppt::container::array::append
*/
template<
	typename Array1,
	typename... Arrays
>
std::array<
	fcppt::type_traits::value_type<
		fcppt::type_traits::remove_cv_ref_t<
			Array1
		>
	>,
	fcppt::metal::from_number<
		std::size_t,
		::metal::accumulate<
			::metal::bind<
				::metal::lambda<
					::metal::add
				>,
				::metal::bind<
					::metal::lambda<
						fcppt::metal::to_number
					>,
					::metal::bind<
						::metal::lambda<
							fcppt::container::array::size
						>,
						::metal::_2
					>
				>,
				::metal::_1
			>,
			fcppt::metal::to_number<
				fcppt::container::array::size<
					fcppt::type_traits::remove_cv_ref_t<
						Array1
					>
				>
			>,
			::metal::list<
				fcppt::type_traits::remove_cv_ref_t<
					Arrays
				>...
			>
		>
	>::value
>
join(
	Array1 &&_array1,
	Arrays &&... _arrays
)
{
	static_assert(
		std::conjunction_v<
			fcppt::type_traits::is_std_array<
				fcppt::type_traits::remove_cv_ref_t<
					Array1
				>
			>,
			fcppt::type_traits::is_std_array<
				fcppt::type_traits::remove_cv_ref_t<
					Arrays
				>
			>...
		>
	);

	static_assert(
		std::conjunction_v<
			std::is_same<
				fcppt::type_traits::value_type<
					fcppt::type_traits::remove_cv_ref_t<
						Array1
					>
				>,
				fcppt::type_traits::value_type<
					fcppt::type_traits::remove_cv_ref_t<
						Arrays
					>
				>
			>...
		>
	);

	return
		fcppt::container::array::detail::join(
			std::forward<
				Array1
			>(
				_array1
			),
			std::forward<
				Arrays
			>(
				_arrays
			)...
		);
}

}
}
}

#endif
