//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_UNTUPLE_HPP_INCLUDED
#define FCPPT_CONTAINER_UNTUPLE_HPP_INCLUDED

#include <fcppt/identity.hpp>
#include <fcppt/algorithm/vararg_map.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{

/**
\brief Passes tuple elements as variadic parameters to a function.

For <code>_tuple = (x_1,...,x_n)</code>, <code>_function(x_1,...,_x_n)</code>
is returned.

\tparam Tuple A tuple type that boost.fusion can iterate over.

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
untuple(
	Tuple &&_tuple,
	Function const &_function
)
{
	return
		fcppt::algorithm::vararg_map(
			std::forward<
				Tuple
			>(
				_tuple
			),
			[
				&_function
			](
				auto &&..._elements
			)
			{
				return
					_function(
						std::forward<
							decltype(
								_elements
							)
						>(
							_elements
						)...
					);
			},
			fcppt::identity{}
		);
}

}
}

#endif
