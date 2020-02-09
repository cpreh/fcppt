//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TUPLE_INIT_HPP_INCLUDED
#define FCPPT_CONTAINER_TUPLE_INIT_HPP_INCLUDED

#include <fcppt/container/tuple/detail/init.hpp>
#include <fcppt/type_traits/is_std_tuple.hpp>
#include <fcppt/config/external_begin.hpp>
#include <tuple>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace tuple
{

/**
\brief Constructs a tuple by calling a function with static indices.

\ingroup fcpptcontainertuple

Constructs a tuple of type \a Tuple by calling
<code>_function(std::integral_constant<std::size_t, Index>)</code> for every index.

\tparam Tuple Must be a <code>std::tuple</code>.

\tparam Function Must be a function callable as <code>T_i
(std::integral_constant<std::size_t, i>)</code> for <code>1 <= i <= n</code>,
where <code>Tuple=(T_1,...,T_n)</code>.
*/
template<
	typename Tuple,
	typename Function
>
inline
Tuple
init(
	Function const &_function
)
{
	static_assert(
		fcppt::type_traits::is_std_tuple<
			Tuple
		>::value,
		"Tuple must be a tuple"
	);

	return
		fcppt::container::tuple::detail::init<
			Tuple
		>(
			std::make_index_sequence<
				std::tuple_size<
					Tuple
				>::value
			>{},
			_function
		);
}

}
}
}

#endif
