//          Copyright Carl Philipp Reh 2009 - 2012.
//          Copyright Philipp Middendorf 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSIGN_DETAIL_INSERT_HPP_INCLUDED
#define FCPPT_ASSIGN_DETAIL_INSERT_HPP_INCLUDED

namespace fcppt
{
namespace assign
{
namespace detail
{

template<
	typename Container
>
void
insert(
	Container &_container,
	typename Container::value_type const &_value
)
{
	_container.insert(
		_container.end(),
		_value
	);
}

}
}
}

#endif
