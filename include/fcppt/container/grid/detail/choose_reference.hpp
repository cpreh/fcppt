//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_DETAIL_CHOOSE_REFERENCE_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_DETAIL_CHOOSE_REFERENCE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/if.hpp>
#include <boost/type_traits/is_const.hpp>
#include <fcppt/config/external_end.hpp>

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
struct choose_reference
:
boost::mpl::if_<
	boost::is_const<
		Container
	>,
	typename Container::const_reference,
	typename Container::reference
>
{
};

}
}
}
}

#endif
