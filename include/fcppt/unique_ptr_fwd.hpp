//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_UNIQUE_PTR_FWD_HPP_INCLUDED
#define FCPPT_UNIQUE_PTR_FWD_HPP_INCLUDED

#include <fcppt/heap_deleter.hpp>

namespace fcppt
{

template<
	typename T,
	template<
		typename
	> class Deleter
	= heap_deleter
>
class unique_ptr;

}

#endif
