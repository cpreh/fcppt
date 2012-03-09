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
\brief Creates a typedef to an aligned type

\ingroup fcpptalignment

Creates a nested typedef 'type' of type \a Type with alignment \a Alignment.
Which alignments are supported is unspecified. In most cases you can only use
alignments that are a power 2. Also, every compiler implements a limit
depending on the platform. If you declare an object of such a type, it might be
possible that its alignment will be larger which depends on the type itself and
if it is allocated on the stack.

\tparam Type The type to typedef

\tparam Alignment The alignment to use
*/
template<
	typename Type,
	fcppt::alignment::size_type Alignment
>
struct make_type
:
fcppt::alignment::detail::make_type<
	Type,
	Alignment
>
{};

}
}

#endif
