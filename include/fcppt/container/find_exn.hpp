//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_FIND_EXN_HPP_INCLUDED
#define FCPPT_CONTAINER_FIND_EXN_HPP_INCLUDED

#include <fcppt/optional_to_exception.hpp>
#include <fcppt/container/find_opt.hpp>
#include <fcppt/container/to_mapped_type.hpp>


namespace fcppt
{
namespace container
{

/**
\brief Returns an element from a find operation or throws an exception

Searches for \a _key in the associative container \a _container. If \a _key is
found, the corresponding mapped type is returned. Otherwise, the result of \a
_make_exception is thrown as an exception.

\ingroup fcpptcontainer

\tparam Container Must be an associative container
*/
template<
	typename Container,
	typename MakeException
>
fcppt::container::to_mapped_type<
	Container
>
find_exn(
	Container &_container,
	typename Container::key_type const &_key,
	MakeException const &_make_exception
)
{
	return
		fcppt::optional_to_exception(
			fcppt::container::find_opt(
				_container,
				_key
			),
			_make_exception
		);
}

}
}

#endif
