//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TUPLE_TO_VARARGS_HPP_INCLUDED
#define FCPPT_CONTAINER_TUPLE_TO_VARARGS_HPP_INCLUDED

#include <fcppt/container/tuple/detail/to_varargs.hpp>
#include <fcppt/type_traits/is_std_tuple.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
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
\brief Passes tuple elements as variadic parameters to a function.

\ingroup fcpptcontainertuple

For <code>_tuple = (x_1,...,x_n)</code>, <code>_function(x_1,...,_x_n)</code>
is returned.

\tparam Tuple Must be a <code>std::tuple</code>.

\tparam Function A function callable as <code>R (T_1,...,T_n)</code>, where
<code>Tuple=(T_1,...,T_n)</code> and <code>R</code> is the result type.
*/
template<
	typename Tuple,
	typename Function
>
inline
decltype(
	auto
)
to_varargs(
	Tuple &&_tuple,
	Function const &_function
)
{
	typedef
	fcppt::type_traits::remove_cv_ref_t<
		Tuple
	>
	tuple_type;

	static_assert(
		fcppt::type_traits::is_std_tuple<
			tuple_type
		>::value,
		"Tuple must be a tuple"
	);

	return
		fcppt::container::tuple::detail::to_varargs(
			std::forward<
				Tuple
			>(
				_tuple
			),
			_function,
			std::make_index_sequence<
				std::tuple_size<
					tuple_type
				>::value
			>{}
		);
}

}
}
}

#endif
