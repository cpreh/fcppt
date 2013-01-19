//          Copyright Carl Philipp Reh 2009 - 2013.
//          Copyright Philipp Middendorf 2009 - 2013.
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
 * \brief Appends the sequence \p src to \p dest.
 * \ingroup fcpptalgorithm
 * \tparam DestContainer Must have an insert function taking three integers (like the std containers all do).
 * \tparam SourceContainer Must have a <code>begin</code> and <code>end</code> member function.
 *
 * Example:
 *
 * \snippet doc/algorithm.cpp append
 **/
template<
	typename DestContainer,
	typename SourceContainer
>
void
append(
	DestContainer &dest,
	SourceContainer const &src
)
{
	dest.insert(
		dest.end(),
		src.begin(),
		src.end()
	);
}

}
}

#endif
