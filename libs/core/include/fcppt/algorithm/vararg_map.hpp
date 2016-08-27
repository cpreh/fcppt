//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_VARARG_MAP_HPP_INCLUDED
#define FCPPT_ALGORITHM_VARARG_MAP_HPP_INCLUDED

#include <fcppt/algorithm/detail/vararg_map.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/begin.hpp>
#include <boost/mpl/end.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief Map an MPL sequence to variadic arguments.

\ingroup fcpptalgorithm

Let \a Sequence be <code>(T_1,...,T_n)</code>. For each <code>T_i</code> in
<code>i = 1,...,n</code> let <code>t_i = _element(fcppt::tag<T_i>)</code>.  The
result is <code>_anchor(t_1,...,t_n)</code>.

\tparam Sequence An MPL sequence.
*/
template<
	typename Sequence,
	typename AnchorFunction,
	typename ElementFunction
>
inline
decltype(
	auto
)
vararg_map(
	AnchorFunction const &_anchor,
	ElementFunction const &_element
)
{
	return
		fcppt::algorithm::detail::vararg_map<
			typename
			boost::mpl::begin<
				Sequence
			>::type,
			typename
			boost::mpl::end<
				Sequence
			>::type
		>::execute(
			_anchor,
			_element
		);
}

}
}

#endif
