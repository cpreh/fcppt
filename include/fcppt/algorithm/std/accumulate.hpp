//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_STD_ACCUMULATE_HPP_INCLUDED
#define FCPPT_ALGORITHM_STD_ACCUMULATE_HPP_INCLUDED

#include <numeric>

namespace fcppt
{
namespace algorithm
{
namespace std
{
template<typename Container, typename T,typename BinaryOp>
T
accumulate(
	Container const &c,
	T const &init,
	BinaryOp const &operation)
{
	return 
		::std::accumulate(
			c.begin(),
			c.end(),
			init,
			operation);
}
}
}
}

#endif
