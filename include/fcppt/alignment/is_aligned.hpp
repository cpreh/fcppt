//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALIGNMENT_IS_ALIGNED_HPP_INCLUDED
#define FCPPT_ALIGNMENT_IS_ALIGNED_HPP_INCLUDED

#include <fcppt/alignment/size_type.hpp>

namespace fcppt
{
namespace alignment
{

/**
\brief Checks if a given pointer is aligned

\ingroup fcpptalignment

Checks if \a _pointer is aligned to \a _alignment

\param _pointer The pointer to check the alignment of

\param _alignment The alignment to check for

\return If the alignment is satisfied
*/
template<
	typename Type
>
bool
is_aligned(
	Type const *const _pointer,
	fcppt::alignment::size_type const _alignment
)
{
	return
		reinterpret_cast<
			fcppt::alignment::size_type
		>(
			_pointer
		)
		% _alignment
		== 0u;
}

}
}

#endif
