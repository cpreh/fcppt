//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALIGNMENT_ARRAY_HPP_INCLUDED
#define FCPPT_ALIGNMENT_ARRAY_HPP_INCLUDED

#include <fcppt/alignment/size_type.hpp>
#include <fcppt/alignment/make_type.hpp>
#include <fcppt/tr1/array.hpp>

namespace fcppt
{
namespace alignment
{

/**
 * @class fcppt::alignment::array array.hpp "fcppt/alignment/array.hpp"
 * @brief Creates a nested typedef 'type' to an std::tr1::array<T, Size> with alignment Alignment
 *
 * This only supports alignments that are a power of 2, starting by 1 and up to FCPPT_ALIGNMENT_MAXIMUM
*/
template<
	typename T,
	size_type Size,
	size_type Alignment
>
struct array
:
make_type<
	std::tr1::array<
		T,
		Size
	>,
	Alignment
>
{};

}
}

#endif
