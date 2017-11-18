//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_SIZE_RESULT_TYPE_HPP_INCLUDED
#define FCPPT_CONTAINER_SIZE_RESULT_TYPE_HPP_INCLUDED

#include <fcppt/container/detail/size.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{

/**
\brief The size type of a range.

\ingroup fcpptcontainer

This type is always unsigned.
*/
template<
	typename Range
>
using
size_result_type
=
typename
std::make_unsigned<
	decltype(
		fcppt::container::detail::size(
			std::declval<
				Range
			>()
		)
	)
>::type;

}
}

#endif
