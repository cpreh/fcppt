//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TUPLE_APPLY_HPP_INCLUDED
#define FCPPT_CONTAINER_TUPLE_APPLY_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/container/tuple/apply_result.hpp>
#include <fcppt/container/tuple/init.hpp>
#include <fcppt/type_traits/is_std_tuple.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <tuple>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace tuple
{

/**
\brief Applies a function to each tuple of elements of multiple tuples and returns an
tuple containing the results.

\ingroup fcpptcontainertuple

Let <code>Tuples=(t_1,...,t_n)</code>, where <code>t_i = u_{i,1}, ..., u_{i,k}</code>.
Calculates <code>r_j = _function(u_{1,j}, ..., u_{n,j})</code> for every
<code>1 <= j <= k</code>.

\tparam Tuples Must be <code>std::tuple</code>s.
**/
template<
	typename Function,
	typename... Tuples
>
fcppt::container::tuple::apply_result<
	Function,
	Tuples...
>
apply(
	Function const &_function,
	Tuples &&... _tuples
)
{
	static_assert(
		std::conjunction<
			fcppt::type_traits::is_std_tuple<
				fcppt::type_traits::remove_cv_ref_t<
					Tuples
				>
			>...
		>::value,
		"Tuples must all be std::tuples"
	);

	static_assert(
		std::is_same_v<
			std::integral_constant<
				std::size_t,
				std::tuple_size_v<
					fcppt::type_traits::remove_cv_ref_t<
						Tuples
					>
				>
			>...
		>,
		"All tuples must have the same size"
	);

	return
		fcppt::container::tuple::init<
			fcppt::container::tuple::apply_result<
				Function,
				Tuples...
			>
		>(
			[
				&_function,
				&_tuples...
			]
			(
				auto const _index
			)
			{
				return
					_function(
						std::get<
							_index()
						>(
							fcppt::move_if_rvalue<
								Tuples
							>(
								_tuples
							)
						)...
					);
			}
		);
}

}
}
}

#endif
