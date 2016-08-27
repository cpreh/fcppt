//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TO_MAPPED_TYPE_HPP_INCLUDED
#define FCPPT_CONTAINER_TO_MAPPED_TYPE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{

/**
\brief Gets the mapped type of an associative container.

\ingroup fcpptcontainer

If \a Container is <code>const</code>, the result is
<code>Container::mapped_type const</code>. Otherwise, it is
<code>Container::mapped_type</code>.

\tparam Container An associative container.
*/
template<
	typename Container
>
using
to_mapped_type
=
typename
std::conditional<
	std::is_const<
		Container
	>::value,
	typename
	Container::mapped_type const,
	typename
	Container::mapped_type
>::type;

}
}

#endif
