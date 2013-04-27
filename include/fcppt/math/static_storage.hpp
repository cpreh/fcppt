//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_STATIC_STORAGE_HPP_INCLUDED
#define FCPPT_MATH_STATIC_STORAGE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <array>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{

template<
	typename T,
	typename N
>
struct static_storage
{
	typedef std::array<
		T,
		N::value
	> type;
};

}
}

#endif
