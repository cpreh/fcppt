//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALIGNMENT_ARRAY_HPP_INCLUDED
#define FCPPT_ALIGNMENT_ARRAY_HPP_INCLUDED

#include <fcppt/alignment/size_type.hpp>
#include <fcppt/alignment/maximum.hpp>
#include <fcppt/alignment/align.hpp>
#include <fcppt/tr1/array.hpp>
#include <boost/preprocessor/arithmetic/mul.hpp>
#include <boost/preprocessor/comparison/less_equal.hpp>
#include <boost/preprocessor/repetition/for.hpp>

namespace fcppt
{
namespace alignment
{

/// Creates a nested typedef 'type' to an std::tr1::array<T, Size> with alignment Alignment
/** This only supports alignments that are a power of 2, starting by 1 and up to FCPPT_ALIGNMENT_MAXIMUM
*/
template<
	typename T,
	size_type Size,
	size_type Alignment
>
struct array;

#define FCPPT_ALIGNMENT_GENERATE_ARRAY(r, state)\
template<\
	typename T,\
	size_type Size\
>\
struct array<\
	T,\
	Size,\
	state\
> {\
	typedef FCPPT_ALIGNMENT_ALIGN(state) std::tr1::array<\
		T,\
		Size\
	> type;\
};

#define FCPPT_ALIGNMENT_GENERATE_ARRAY_END(r, state)\
	BOOST_PP_LESS_EQUAL(\
		state,\
		FCPPT_ALIGNMENT_MAXIMUM\
	)

#define FCPPT_ALIGNMENT_GENERATE_ARRAY_ADD(r, state)\
	BOOST_PP_MUL(state, 2)

BOOST_PP_FOR(
	1,
	FCPPT_ALIGNMENT_GENERATE_ARRAY_END,
	FCPPT_ALIGNMENT_GENERATE_ARRAY_ADD,
	FCPPT_ALIGNMENT_GENERATE_ARRAY
)

#undef FCPPT_ALIGNMENT_GENERATE_ARRAY_ADD
#undef FCPPT_ALIGNMENT_GENERATE_ARRAY_END
#undef FCPPT_ALIGNMENT_GENERATE_ARRAY

}
}

#endif
