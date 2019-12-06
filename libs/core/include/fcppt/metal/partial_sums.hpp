//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_METAL_PARTIAL_SUMS_HPP_INCLUDED
#define FCPPT_METAL_PARTIAL_SUMS_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <metal.hpp>
#include <metal.hpp>
#include <metal.hpp>
#include <metal.hpp>
#include <metal.hpp>
#include <metal.hpp>
#include <metal.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace metal
{

/**
\brief Calculates a new sequence that consists of the sums of the old sequence.

\ingroup fcpptmetal

For the integral constants <code>(c_1, ..., c_n)</code> in \a Sequence, the resulting
sequence will consist of the values <code>(0, c_1, c_1 + c_2, ..., c_1 + ... c_n)</code>.

\tparam Sequence A metal::list of metal::numbers.
*/
template<
	typename Sequence
>
using
partial_sums
=
::metal::accumulate<
	::metal::bind<
		::metal::lambda<
			::metal::append
		>,
		::metal::_1,
		::metal::bind<
			::metal::lambda<
				::metal::add
			>,
			::metal::bind<
				::metal::lambda<
					::metal::back
				>,
				::metal::_1
			>,
			::metal::_2
		>
	>,
	::metal::list<
		::metal::number<
			0
		>
	>,
	Sequence
>;

}
}

#endif
