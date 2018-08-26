//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_FIND_OPT_MAPPED_HPP_INCLUDED
#define FCPPT_CONTAINER_FIND_OPT_MAPPED_HPP_INCLUDED

#include <fcppt/make_ref.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/container/find_opt.hpp>
#include <fcppt/container/to_mapped_type.hpp>
#include <fcppt/container/to_value_type.hpp>
#include <fcppt/optional/map.hpp>
#include <fcppt/optional/object_impl.hpp>


namespace fcppt
{
namespace container
{

/**
\brief Returns an element from a find operation or an empty optional.

Searches for \a _key in the associative container \a _container. If \a _key is
found, the corresponding mapped object is returned. Otherwise, the empty optional
is returned.

\ingroup fcpptcontainer

\tparam Container Must be an associative container.

\tparam Key Must be a key that can be searched for.
*/
template<
	typename Container,
	typename Key
>
inline
fcppt::optional::object<
	fcppt::reference<
		fcppt::container::to_mapped_type<
			Container
		>
	>
>
find_opt_mapped(
	Container &_container,
	Key const &_key
)
{
	return
		fcppt::optional::map(
			fcppt::container::find_opt(
				_container,
				_key
			),
			[](
				fcppt::reference<
					fcppt::container::to_value_type<
						Container
					>
				> const _value
			)
			{
				return
					fcppt::make_ref(
						_value.get().second
					);
			}
		);
}

}
}

#endif
