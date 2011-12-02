//          Copyright Carl Philipp Reh 2009 - 2011.
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
 * FIXME
 * \ingroup fcpptalignment
 */
template<
	typename T
>
bool
is_aligned(
	T const *const pointer,
	size_type const alignment
)
{
	return
		reinterpret_cast<
			size_type
		>(
			pointer
		)
		% alignment
		== 0;
}

}
}

#endif
