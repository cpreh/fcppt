//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_RAW_VECTOR_FWD_HPP_INCLUDED
#define FCPPT_CONTAINER_RAW_VECTOR_FWD_HPP_INCLUDED

#include <memory>

namespace fcppt
{
namespace container
{

template<
	typename T,
	typename A = std::allocator<T>
>
class raw_vector;

}
}

#endif
