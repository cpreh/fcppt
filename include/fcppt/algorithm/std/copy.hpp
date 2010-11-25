//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


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
