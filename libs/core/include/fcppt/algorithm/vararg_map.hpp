//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_VARARG_MAP_HPP_INCLUDED
#define FCPPT_ALGORITHM_VARARG_MAP_HPP_INCLUDED

#include <fcppt/algorithm/detail/vararg_map.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/fusion/sequence/intrinsic/begin.hpp>
#include <boost/fusion/sequence/intrinsic/end.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief Map a fusion sequence to variadic arguments.

\ingroup fcpptalgorithm

Let \a _tuple be <code>(v_1,...,v_n)</code>. The result is
<code>_anchor(_element(v_1),...,_element(v_n))</code>.

\note The main purpose of this function is that the mapping function \a
_element is called in order of the arguments, which is impossible to do with
<code>boost.fusion</code> alone.

\tparam Tuple A fusion sequence.
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
	AnchorFunction const &_anchor,
	ElementFunction const &_element
)
{
	typedef
	typename
	std::remove_reference<
		Tuple
	>::type
	decayed;

	return
		fcppt::algorithm::detail::vararg_map<
			!std::is_lvalue_reference<
				Tuple
			>::value,
			typename
			boost::fusion::result_of::begin<
				decayed
			>::type,
			typename
			boost::fusion::result_of::end<
				decayed
			>::type
		>::execute(
			boost::fusion::begin(
				_tuple
			),
			boost::fusion::end(
				_tuple
			),
			_anchor,
			_element
		);
}

}
}

#endif
