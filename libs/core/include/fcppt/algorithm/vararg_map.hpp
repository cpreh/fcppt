//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_VARARG_MAP_HPP_INCLUDED
#define FCPPT_ALGORITHM_VARARG_MAP_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/container/untuple.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief Map a std::tuple to variadic arguments.

\ingroup fcpptalgorithm

Let \a _tuple be <code>(v_1,...,v_n)</code>. The result is
<code>_anchor_function(_element_function(v_1),...,_element_function(v_n))</code>.

\tparam Tuple A std::tuple.
*/
template<
	typename Tuple,
	typename AnchorFunction,
	typename ElementFunction
>
inline
decltype(
	auto
)
vararg_map(
	Tuple &&_tuple,
	AnchorFunction const &_anchor_function,
	ElementFunction const &_element_function
)
{
	return
		fcppt::container::untuple(
			std::forward<
				Tuple
			>(
				_tuple
			),
			[
				&_anchor_function,
				&_element_function
			](
				auto &&... _fcppt_vararg_args
			)
			{
				return
					_anchor_function(
						_element_function(
							fcppt::move_if_rvalue<
								Tuple
							>(
								_fcppt_vararg_args
							)
						)...
					);
			}
		);
}

}
}

#endif
