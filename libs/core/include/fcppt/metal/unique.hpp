//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_METAL_UNIQUE_HPP_INCLUDED
#define FCPPT_METAL_UNIQUE_HPP_INCLUDED

#include <fcppt/metal/set/from_list_relaxed.hpp>
#include <fcppt/metal/set/to_list.hpp>


namespace fcppt
{
namespace metal
{

/**
\brief Removes duplicates from a metal::list.

\ingroup fcpptrecord

\tparam Sequence Must be a metal::list.
*/
template<
	typename Sequence
>
using
unique
=
fcppt::metal::set::to_list<
	fcppt::metal::set::from_list_relaxed<
		Sequence
	>
>;

}
}

#endif
