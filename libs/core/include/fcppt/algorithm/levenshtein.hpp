//          Copyright Carl Philipp Reh 2009 - 2015.
//          Copyright Philipp Middendorf 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_LEVENSHTEIN_HPP_INCLUDED
#define FCPPT_ALGORITHM_LEVENSHTEIN_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/cast/to_signed.hpp>
#include <fcppt/cast/to_unsigned.hpp>
#include <fcppt/container/grid/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/range/empty.hpp>
#include <boost/range/size.hpp>
#include <boost/range/size_type.hpp>
#include <boost/range/value_type.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief Calculates the Levenshtein distance
\ingroup fcpptalgorithm
\details
See http://en.wikipedia.org/wiki/Levenshtein_distance for an explanation of the algorithm.
\pre
<ul>
<li><code>Range::size_type</code> and <code>Range::value_type</code> exist</li>
<li><code>bool Range::empty() const</code> exists</li>
<li><code>size_type Range::size() const</code> exists</li>
<li><code>Range::operator[]</code> exists</li>
<li><code>Range::value_type</code> has to have an <code>operator==</code></li>
</ul>

\note
The code is taken quite literally from:
http://www.merriampark.com/ldcpp.htm
*/
template<typename Range>
typename
boost::range_size<Range>::type
levenshtein(
	Range const &source,
	Range const &target)
{
	typedef typename
	boost::range_size<Range>::type
	size_type;

	typedef typename
	boost::range_difference<Range>::type
	difference_type;

	typedef typename
	boost::range_value<Range>::type
	element_type;

	size_type const
		n =
			boost::size(
				source),
		m =
			boost::size(
				target);

	if(boost::empty(source))
		return m;

	if(boost::empty(target))
		return n;

	typedef
	fcppt::container::grid::object
	<
		size_type,
		2
	>
	grid;

	typedef typename
	grid::dim
	dim;

	typedef typename
	grid::pos
	pos;

	grid matrix(
		dim(
			n + 1,
			m + 1
		),
		fcppt::literal<
			size_type
		>(
			0
		)
	);

	// Step 2

	for (size_type i = 0; i <= n; i++)
		matrix[pos(i,0u)] = i;

	for (size_type j = 0; j <= m; j++)
		matrix[pos(0u,j)] = j;

	for (difference_type i = 1; i <= fcppt::cast::to_signed(n); i++)
	{
		element_type const &s_i =
			*(boost::begin(
				source) +
			i-1);

		for (difference_type j = 1; j <= fcppt::cast::to_signed(m); j++)
		{
			element_type const &t_j =
				*(boost::begin(
					target) +
				j-1);

			size_type const cost(
				s_i == t_j
				?
					0u
				:
					1u
			);

			// Step 6

			size_type const
				above =
					matrix[
						pos(
							fcppt::cast::to_unsigned(
								i-1),
							fcppt::cast::to_unsigned(
								j))],
				left =
					matrix[
						pos(
							fcppt::cast::to_unsigned(
								i),
							fcppt::cast::to_unsigned(
								j-1))],
				diag =
					matrix[
						pos(
							fcppt::cast::to_unsigned(
								i-1),
							fcppt::cast::to_unsigned(
								j-1))];

			size_type cell =
				::std::min(
					above + 1u,
					::std::min(
						left + 1u,
						diag + cost));

			// Step 6A: Cover transposition, in addition to deletion,
			// insertion and substitution. This step is taken from:
			// Berghel, Hal ; Roach, David : "An Extension of Ukkonen's
			// Enhanced Dynamic Programming ASM Algorithm"
			// (http://www.acm.org/~hlb/publications/asm/asm.html)
			if(i>fcppt::literal<difference_type>(2) && j>fcppt::literal<difference_type>(2))
			{
				size_type trans =
					matrix[
						pos(
							fcppt::cast::to_unsigned(
								i-2),
							fcppt::cast::to_unsigned(
								j-2))
					] +
						1u;

				if(*(boost::begin(source) + i-2) != t_j)
					trans++;

				if(s_i != *(boost::begin(target) + j-2))
					trans++;

				if(cell>trans)
					cell = trans;
			}

			matrix[
				pos(
					fcppt::cast::to_unsigned(
						i),
					fcppt::cast::to_unsigned(
						j))] =
				cell;
		}
	}

	return
		matrix[
			pos(
				n,
				m
			)
		];
}

}
}

#endif
