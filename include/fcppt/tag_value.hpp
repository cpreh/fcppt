//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TAG_VALUE_HPP_INCLUDED
#define FCPPT_TAG_VALUE_HPP_INCLUDED

#include <fcppt/tag.hpp>


namespace fcppt
{

/**
\brief Extracts the value of \link fcppt::tag\endlink

Useful for extracting integral constants from tags.

\ingroup fcpptvarious
*/
template<
	typename Type
>
constexpr
inline
Type
tag_value(
	fcppt::tag<
		Type
	>
)
{
	return
		Type{};
}

}

#endif
