#ifndef FCPPT_ALGORITHM_STD_ACCUMULATE_HPP_INCLUDED
#define FCPPT_ALGORITHM_STD_ACCUMULATE_HPP_INCLUDED

#include <algorithm>

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
