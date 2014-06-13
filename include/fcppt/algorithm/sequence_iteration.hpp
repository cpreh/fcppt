//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_SEQUENCE_ITERATION_HPP_INCLUDED
#define FCPPT_ALGORITHM_SEQUENCE_ITERATION_HPP_INCLUDED


namespace fcppt
{
namespace algorithm
{

/**
\brief Iterates over a sequence with the possibility of erasing elements

\ingroup fcpptalgorithm

Iterates over \a _sequence, applying \a _update_action to each element. If \a
_update_action returns false, the element is deleted from the sequence.
*/
template<
	typename Sequence,
	typename UpdateAction
>
void
sequence_iteration(
	Sequence &_sequence,
	UpdateAction const &_update_action
)
{
	for(
		auto it(
			_sequence.begin()
		);
		it != _sequence.end();
	)
	{
		if(
			_update_action(
				*it
			)
		)
			it =
				_sequence.erase(
					it
				);
		else
			++it;
	}
}

}
}

#endif
