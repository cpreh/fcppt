//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TO_VALUE_TYPE_HPP_INCLUDED
#define FCPPT_CONTAINER_TO_VALUE_TYPE_HPP_INCLUDED

#include <fcppt/container/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{

/**
\brief The value type of a container depending on its constness.

\ingroup fcpptcontainer

If \a Container is <code>const</code>, the result is
<code>Container::value_type const</code>. Otherwise, it is
<code>Container::value_type</code>.

\tparam Container A range type.
*/
template<
	typename Container
>
using
to_value_type
=
std::conditional_t<
	std::is_const<
		Container
	>::value,
	fcppt::container::value_type<
		Container
	> const,
	fcppt::container::value_type<
		Container
	>
>;

}
}

#endif
