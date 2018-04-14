//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_STRONG_TYPEDEF_TAG_HPP_INCLUDED
#define FCPPT_STRONG_TYPEDEF_TAG_HPP_INCLUDED

#include <fcppt/detail/strong_typedef_tag.hpp>


namespace fcppt
{

/**
\brief The tag type of a strong typedef.

\ingroup fcpptstrongtypedef

\tparam StrongTypedef Must be an \link fcppt::strong_typedef\endlink.
*/
template<
	typename StrongTypedef
>
using
strong_typedef_tag
=
typename
fcppt::detail::strong_typedef_tag<
	StrongTypedef
>::type;

}

#endif
