//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_VALUE_TYPE_HPP_INCLUDED
#define FCPPT_CONTAINER_VALUE_TYPE_HPP_INCLUDED


namespace fcppt
{
namespace container
{

/**
\brief The value type of a container.

\ingroup fcpptcontainer
*/
template<
	typename Container
>
using
value_type
=
typename
Container::value_type;

}
}

#endif
