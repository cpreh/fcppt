//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_MAYBE_FRONT_HPP_INCLUDED
#define FCPPT_CONTAINER_MAYBE_FRONT_HPP_INCLUDED

#include <fcppt/optional_impl.hpp>
#include <fcppt/container/to_reference_type.hpp>


namespace fcppt
{
namespace container
{

/**
\brief Returns the front of a container as an optional

\ingroup fcpptcontainer
*/
template<
	typename Container
>
fcppt::optional<
	fcppt::container::to_reference_type<
		Container
	>
>
maybe_front(
	Container &_container
)
{
	typedef
	fcppt::optional<
		fcppt::container::to_reference_type<
			Container
		>
	>
	result_type;

	return
		_container.empty()
		?
			result_type()
		:
			result_type(
				_container.front()
			)
		;
}

}
}

#endif
