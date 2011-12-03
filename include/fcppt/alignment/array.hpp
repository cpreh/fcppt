//          Copyright Carl Philipp Reh 2009 - 2011.
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
\brief Creates a nested typedef <code>type</code> to an <code>fcppt::container::array<T, Size></code> with alignment \p Alignment
\ingroup fcpptalignment
\tparam Alignment TODO
\see fcppt::alignment::make_type
*/
template<
	typename T,
	size_type Size,
	size_type Alignment
>
struct array
:
fcppt::alignment::make_type<
	fcppt::container::array<
		T,
		Size
	>,
	Alignment
>
{};

}
}

#endif
