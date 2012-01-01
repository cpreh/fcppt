//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALIGNMENT_MAKE_TYPE_HPP_INCLUDED
#define FCPPT_ALIGNMENT_MAKE_TYPE_HPP_INCLUDED

#include <fcppt/alignment/size_type.hpp>
#include <fcppt/alignment/detail/make_type.hpp>


namespace fcppt
{
namespace alignment
{

/**
\brief Creates a nested typedef 'type' of type <code>T</code> with alignment <code>Alignment</code>
\ingroup fcpptalignment
\details
Which alignments are supported is unspecified.  In most cases you can only use
alignments that are a power 2.  Also, every compiler implements a limit
depending on the platform.
*/
template<
	typename T,
	size_type Alignment
>
struct make_type
:
fcppt::alignment::detail::make_type<
	T,
	Alignment
>
{};

}
}

#endif
