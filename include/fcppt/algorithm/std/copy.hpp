#ifndef FCPPT_ALGORITHM_STD_COPY_HPP_INCLUDED
#define FCPPT_ALGORITHM_STD_COPY_HPP_INCLUDED

#include <algorithm>

namespace fcppt
{
namespace algorithm
{
namespace std
{
template<typename Container,typename OutputIterator>
OutputIterator
copy(
	Container const &c,
	OutputIterator const &oit)
{
	return 
		::std::copy(
			c.begin(),
			c.end(),
			oit);
}
}
}
}

#endif
