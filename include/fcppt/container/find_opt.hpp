//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_FIND_OPT_HPP_INCLUDED
#define FCPPT_CONTAINER_FIND_OPT_HPP_INCLUDED

#include <fcppt/optional_impl.hpp>
#include <fcppt/container/to_mapped_type.hpp>


namespace fcppt
{
namespace container
{

/**
\brief Returns and element from a find operation or an empty optional

Searches for \a _key in the associative container \a _container. If \a _key is
found, the corresponding mapped type is returned. Otherwise, and empty optional
is returned.

\ingroup fcpptcontainer

\tparam Container Must be an associative container
*/
template<
	typename Container
>
fcppt::optional<
	fcppt::container::to_mapped_type<
		Container
	>
>
find_opt(
	Container &_container,
	typename Container::key_type const &_key
)
{
	auto const it(
		_container.find(
			_key
		)
	);

	typedef
	fcppt::optional<
		fcppt::container::to_mapped_type<
			Container
		>
	>
	result_type;

	return
		it
		!=
		_container.end()
		?
			result_type(
				it->second
			)
		:
			result_type()
		;
}

}
}

#endif
