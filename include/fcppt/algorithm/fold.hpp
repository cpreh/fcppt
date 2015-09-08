//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_FOLD_HPP_INCLUDED
#define FCPPT_ALGORITHM_FOLD_HPP_INCLUDED

#include <fcppt/algorithm/loop.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief Folds a container into a value

\ingroup fcpptalgorithm

Like fold_left a in functional programming language, this function starts with
\a _state as <code>cur_state</code>, and calls <code> cur_state =
_function(element, cur_state)</code> for every element of \a _container.

\tparam Container Must be a sequence

\tparam State Has to be movable or copyable

\tparam Function Must be callable with elements of \a Container and \a State,
returning a \a State
**/
template<
	typename Container,
	typename State,
	typename Function
>
inline
State
fold(
	Container &&_container,
	State _state,
	Function _function
)
{
	fcppt::algorithm::loop(
		std::forward<
			Container
		>(
			_container
		),
		[
			&_state,
			&_function
		](
			auto &&_fcppt_element
		)
		{
			_state =
				_function(
					_fcppt_element,
					std::move(
						_state
					)
				);
		}
	);

	return
		_state;
}

}
}

#endif
