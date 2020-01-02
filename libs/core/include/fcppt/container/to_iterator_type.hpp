//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TO_ITERATOR_TYPE_HPP_INCLUDED
#define FCPPT_CONTAINER_TO_ITERATOR_TYPE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{

/**
\brief Gets the iterator type of a container.

\ingroup fcpptcontainer

If \a Container is <code>const</code>, the result is
<code>Container::const_iterator</code>. Otherwise, it is
<code>Container::iterator</code>.

\tparam Container A range type.
*/
template<
	typename Container
>
using
to_iterator_type
=
std::conditional_t<
	std::is_const<
		Container
	>::value,
	typename
	Container::const_iterator,
	typename
	Container::iterator
>;

}
}

#endif
