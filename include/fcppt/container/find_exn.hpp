//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_FIND_EXN_HPP_INCLUDED
#define FCPPT_CONTAINER_FIND_EXN_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/if.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{

/**
\brief Returns and element from a find operation or throws an exception

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
typename
boost::mpl::if_<
	std::is_const<
		Container
	>,
	typename
	Container::mapped_type const &,
	typename
	Container::mapped_type &
>::type
find_exn(
	Container &_container,
	typename Container::key_type const &_key,
	MakeException const &_make_exception
)
{
	auto const it(
		_container.find(
			_key
		)
	);

	if(
		it
		==
		_container.end()
	)
		throw
			_make_exception();

	return
		it->second;
}

}
}

#endif
