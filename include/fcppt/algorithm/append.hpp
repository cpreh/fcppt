//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_APPEND_HPP_INCLUDED
#define FCPPT_ALGORITHM_APPEND_HPP_INCLUDED


namespace fcppt
{
namespace algorithm
{

/**
\brief Appends two sequences.

\ingroup fcpptalgorithm

\tparam DestContainer Must have an insert function taking three integers (like the std containers all do).

\tparam SourceContainer Must have a <code>begin</code> and <code>end</code> member function.

Appends the sequence \a _src to \a _dest.

Example:

\snippet doc/algorithm.cpp append
**/
template<
	typename DestContainer,
	typename SourceContainer
>
void
append(
	DestContainer &_dest,
	SourceContainer const &_src
)
{
	_dest.insert(
		_dest.end(),
		_src.begin(),
		_src.end()
	);
}

}
}

#endif
