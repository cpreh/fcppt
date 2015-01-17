//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_DATA_END_HPP_INCLUDED
#define FCPPT_CONTAINER_DATA_END_HPP_INCLUDED

#include <fcppt/cast/to_signed.hpp>
#include <fcppt/container/data.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{

/**
\brief Returns a pointer one past the end of a random access container

\ingroup fcpptcontainer

\param _container The container to return the pointer for
*/
template<
	typename Container
>
typename
std::conditional<
	std::is_const<
		Container
	>::value,
	typename
	Container::const_pointer,
	typename
	Container::pointer
>::type
data_end(
	Container &_container
)
{
	auto const result(
		fcppt::container::data(
			_container
		)
	);

	return
		_container.empty()
		?
			result
		:
			result
			+
			fcppt::cast::to_signed(
				_container.size()
			)
		;
}

}
}

#endif
