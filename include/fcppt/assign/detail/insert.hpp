//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSIGN_DETAIL_INSERT_HPP_INCLUDED
#define FCPPT_ASSIGN_DETAIL_INSERT_HPP_INCLUDED

#include <fcppt/container/is_associative.hpp>
#include <boost/utility/enable_if.hpp>

namespace fcppt
{
namespace assign
{
namespace detail
{

template<
	typename Container
>
typename boost::enable_if<
	container::is_associative<
		Container
	>,
	void
>::type
insert(
	Container &container_,
	typename Container::value_type const &x
)
{
	container_.insert(
		x
	);
}

template<
	typename Container
>
typename boost::disable_if<
	container::is_associative<
		Container
	>,
	void
>::type
insert(
	Container &container_,
	typename Container::value_type const &x
)
{
	container_.push_back(
		x
	);
}



}
}
}

#endif
