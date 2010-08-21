
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
