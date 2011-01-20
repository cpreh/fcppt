//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_DATA_END_HPP_INCLUDED
#define FCPPT_CONTAINER_DATA_END_HPP_INCLUDED

namespace fcppt
{
namespace container
{

template<
	typename Container
>
typename Container::pointer
data_end(
	Container &c
)
{
	return c.empty() ? 0 : &c[0] + c.size();
}

template<
	typename Container
>
typename Container::const_pointer
data_end(
	Container const &c
)
{
	return c.empty() ? 0 : &c[0] + c.size();
}

}
}

#endif
