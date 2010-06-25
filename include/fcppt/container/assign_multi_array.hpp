//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_ASSIGN_MULTI_ARRAY_HPP_INCLUDED
#define FCPPT_CONTAINER_ASSIGN_MULTI_ARRAY_HPP_INCLUDED

#include <boost/multi_array.hpp>
#include <fcppt/tr1/array.hpp>
#include <fcppt/algorithm/copy_n.hpp>
#include <cstddef>

namespace fcppt
{
namespace container
{

/// Assigns the multi_array @a right to @a left
/**
 * First, @a left will get resized to fit the size of @a right
 * and then assigned.
 * Note that this operation might be slower than expected
 * because resizing already requires all the elements to be copied.
*/
template
<
	typename T,
	std::size_t N
>
void
assign_multi_array(
	boost::multi_array<T,N> &left,
	boost::multi_array<T,N> const &right)
{
	std::tr1::array
	<
		typename boost::multi_array
		<
			T,
			N
		>::size_type,
		N
	> a;

	algorithm::copy_n(
		right.shape(),
		right.num_dimensions(),
		a.begin());

	left.resize(
		a);

	left = right;
}

}
}

#endif
