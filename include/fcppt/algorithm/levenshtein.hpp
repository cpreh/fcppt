//          Copyright Carl Philipp Reh 2009 - 2012.
//          Copyright Philipp Middendorf 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_LEVENSHTEIN_HPP_INCLUDED
#define FCPPT_ALGORITHM_LEVENSHTEIN_HPP_INCLUDED

#include <fcppt/container/grid/object.hpp>
#include <fcppt/math/dim/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/range/empty.hpp>
#include <boost/range/size.hpp>
#include <boost/range/size_type.hpp>
#include <boost/range/value_type.hpp>
#include <boost/type_traits/make_unsigned.hpp>
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

	// This doesn't have to be a char_type, it's just called that way :>
	typedef typename
	boost::range_value<Range>::type
	char_type;

	size_type const
		n =
			static_cast<size_type>(
				boost::size(
					source)),
		m =
			static_cast<size_type>(
				boost::size(
					target));

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
	dim::value_type
	dimension_type;

	grid matrix(
		dim(
			static_cast<dimension_type>(
				n+1),
			static_cast<dimension_type>(
				m+1)));

	// Step 2

	for (size_type i = 0; i <= n; i++)
		matrix[dim(static_cast<dimension_type>(i),0u)] = i;

	for (size_type j = 0; j <= m; j++)
		matrix[dim(0u,static_cast<dimension_type>(j))] = j;

	for (difference_type i = 1; i <= static_cast<difference_type>(n); i++)
	{
		char_type const &s_i =
			*(boost::begin(
				source) +
			i-1);

		for (difference_type j = 1; j <= static_cast<difference_type>(m); j++)
		{
			char_type const &t_j =
				*(boost::begin(
					target) +
				j-1);

			size_type cost;
			if (s_i == t_j)
				cost = 0u;
			else
				cost = 1u;

			// Step 6

			size_type const
				above =
					matrix[
						dim(
							static_cast<dimension_type>(
								i-1),
							static_cast<dimension_type>(
								j))],
				left =
					matrix[
						dim(
							static_cast<dimension_type>(
								i),
							static_cast<dimension_type>(
								j-1))],
				diag =
					matrix[
						dim(
							static_cast<dimension_type>(
								i-1),
							static_cast<dimension_type>(
								j-1))];

			size_type cell =
				::std::min(
					static_cast<size_type>(
						above + 1u),
					::std::min(
						static_cast<size_type>(
							left + 1u),
						static_cast<size_type>(
							diag + cost)));

			// Step 6A: Cover transposition, in addition to deletion,
			// insertion and substitution. This step is taken from:
			// Berghel, Hal ; Roach, David : "An Extension of Ukkonen's
			// Enhanced Dynamic Programming ASM Algorithm"
			// (http://www.acm.org/~hlb/publications/asm/asm.html)
			if(i>static_cast<difference_type>(2) && j>static_cast<difference_type>(2))
			{
				size_type trans =
					static_cast<size_type>(
						matrix[
							dim(
								static_cast<dimension_type>(
									i-2),
								static_cast<dimension_type>(
									j-2))] +
							1u);

				if(*(boost::begin(source) + i-2) != t_j)
					trans++;

				if(s_i != *(boost::begin(target) + j-2))
					trans++;

				if(cell>trans)
					cell = trans;
			}

			matrix[
				dim(
					static_cast<dimension_type>(
						i),
					static_cast<dimension_type>(
						j))] =
				cell;
		}
	}

	return
		matrix[
			dim(
				static_cast<dimension_type>(
					n),
				static_cast<dimension_type>(
					m))];
}
}
}

#endif
