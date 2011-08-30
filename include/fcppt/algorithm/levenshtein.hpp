//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_LEVENSHTEIN_HPP_INCLUDED
#define FCPPT_ALGORITHM_LEVENSHTEIN_HPP_INCLUDED

#include <fcppt/container/grid/object.hpp>
#include <fcppt/math/dim/basic_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace algorithm
{
/// Calculates the Levenshtein distance (see
/// http://en.wikipedia.org/wiki/Levenshtein_distance) between two
/// arbitrary containers of the same type "Container".
/// Requirements are:
/// - Container::size_type and Container::value_type exist
/// - bool empty() const exists
/// - size_type size() const exists
/// - operator[] exists
/// - value_type has to have operator==
///
/// Note that the code is taken quite literally from:
///
/// http://www.merriampark.com/ldcpp.htm
template<typename Container>
typename
Container::size_type
levenshtein(
	Container const &source,
	Container const &target)
{
	typedef typename
	Container::size_type
	result_type;

	// This doesn't have to be a char_type, it's just called that way :>
	typedef typename
	Container::value_type
	char_type;

	result_type const
		n = source.size(),
		m = target.size();

	if (source.empty())
		return m;
	if (target.empty())
		return n;

	typedef
	fcppt::container::grid::object
	<
		result_type,
		2
	>
	grid;

	typedef typename
	grid::dim
	dim;

	grid matrix(
		dim(
			static_cast<result_type>(
				n+1),
			static_cast<result_type>(
				m+1)));

  // Step 2

  for (result_type i = 0; i <= n; i++)
    matrix[dim(i,0)] = i;

  for (result_type j = 0; j <= m; j++)
    matrix[dim(0,j)] = j;

  for (result_type i = 1; i <= n; i++)
	{
    char_type const &s_i =
			source[i-1];

    for (result_type j = 1; j <= m; j++)
		{
      char_type const &t_j =
				target[j-1];

      result_type cost;
      if (s_i == t_j)
        cost = 0;
      else
        cost = 1;

      // Step 6

      result_type const
				above = matrix[dim(i-1,j)],
				left = matrix[dim(i,j-1)],
				diag = matrix[dim(i-1,j-1)];
			result_type
				cell = ::std::min(above + 1,::std::min(left + 1, diag + cost));

      // Step 6A: Cover transposition, in addition to deletion,
      // insertion and substitution. This step is taken from:
      // Berghel, Hal ; Roach, David : "An Extension of Ukkonen's
      // Enhanced Dynamic Programming ASM Algorithm"
      // (http://www.acm.org/~hlb/publications/asm/asm.html)
      if (i>static_cast<result_type>(2) && j>static_cast<result_type>(2))
			{
        result_type trans = matrix[dim(i-2,j-2)]+1;
        if (source[i-2]!=t_j) trans++;
        if (s_i!=target[j-2]) trans++;
        if (cell>trans) cell = trans;
      }

      matrix[dim(i,j)] = cell;
    }
  }

  return matrix[dim(n,m)];
}
}
}

#endif
