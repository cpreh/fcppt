//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_OUTPUT_HPP_INCLUDED
#define FCPPT_CONTAINER_OUTPUT_HPP_INCLUDED

#include <fcppt/container/detail/output.hpp>
#include <fcppt/type_traits/is_iterator_of_category.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iterator>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{

/**
\brief Creates a class that has an output operator to print a container.

\ingroup fcpptcontainer

\tparam Container Must be a container that has at least a forward iterator.
*/
template<
	typename Container
>
inline
fcppt::container::detail::output<
	Container
>
output(
	Container const &_container
)
noexcept
{
	static_assert(
		fcppt::type_traits::is_iterator_of_category<
			typename
			Container::const_iterator,
			std::forward_iterator_tag
		>::value,
		"Container must provide a forward iterator!"
	);

	return
		fcppt::container::detail::output<
			Container
		>{
			_container
		};
}

}
}

#endif
