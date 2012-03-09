//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALIGNMENT_ARRAY_HPP_INCLUDED
#define FCPPT_ALIGNMENT_ARRAY_HPP_INCLUDED

#include <fcppt/alignment/make_type.hpp>
#include <fcppt/alignment/size_type.hpp>
#include <fcppt/container/array.hpp>


namespace fcppt
{
namespace alignment
{

/**
\brief Creates an array with a given alignment

\ingroup fcpptalignment

Contains a nested typedef <code>type</code> to an
<code>fcppt::container::array<Type, Size></code> with alignment \a Alignment

\tparam Type Can be any type

\tparam Size The size of the array

\tparam Alignment The alignment to use for the array

\see fcppt::alignment::make_type
*/
template<
	typename Type,
	fcppt::alignment::size_type Size,
	fcppt::alignment::size_type Alignment
>
struct array
:
fcppt::alignment::make_type<
	fcppt::container::array<
		Type,
		Size
	>,
	Alignment
>
{};

}
}

#endif
