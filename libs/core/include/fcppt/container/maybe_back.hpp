//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_MAYBE_BACK_HPP_INCLUDED
#define FCPPT_CONTAINER_MAYBE_BACK_HPP_INCLUDED

#include <fcppt/make_ref.hpp>
#include <fcppt/container/to_value_type.hpp>
#include <fcppt/optional/reference.hpp>


namespace fcppt
{
namespace container
{

/**
\brief Returns the back of a container as an optional.

\ingroup fcpptcontainer
*/
template<
	typename Container
>
fcppt::optional::reference<
	fcppt::container::to_value_type<
		Container
	>
>
maybe_back(
	Container &_container
)
{
	typedef
	fcppt::optional::reference<
		fcppt::container::to_value_type<
			Container
		>
	>
	result_type;

	return
		_container.empty()
		?
			result_type{}
		:
			result_type{
				fcppt::make_ref(
					_container.back()
				)
			}
		;
}

}
}

#endif
