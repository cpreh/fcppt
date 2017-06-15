//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TAG_HPP_INCLUDED
#define FCPPT_TAG_HPP_INCLUDED

#include <fcppt/tag_fwd.hpp>


namespace fcppt
{

/**
\brief A value for a type name

\ingroup fcpptvarious

This class can be used to pass the type \a Type as a value.
*/
template<
	typename Type
>
struct tag
{
	typedef
	Type
	type;
};

}

#endif
