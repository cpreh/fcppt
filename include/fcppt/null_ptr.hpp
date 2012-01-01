//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_NULL_PTR_HPP_INCLUDED
#define FCPPT_NULL_PTR_HPP_INCLUDED

#include <fcppt/detail/nullptr_t.hpp>


namespace fcppt
{

inline
detail::nullptr_t const
null_ptr()
{
	return detail::nullptr_t();
}

}

#endif
