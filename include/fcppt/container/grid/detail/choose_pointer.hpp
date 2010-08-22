//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_DETAIL_CHOOSE_POINTER_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_DETAIL_CHOOSE_POINTER_HPP_INCLUDED

#include <boost/mpl/if.hpp>

namespace fcppt
{
namespace container
{
namespace grid
{
namespace detail
{

template<
	typename Container
>
struct choose_pointer
:
boost::mpl::if_<
	boost::is_const<
		Container
	>,
	typename Container::const_pointer,
	typename Container::pointer
>
{
};

}
}
}
}

#endif
