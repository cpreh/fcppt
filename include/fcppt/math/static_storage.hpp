//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_STATIC_STORAGE_HPP_INCLUDED
#define FCPPT_MATH_STATIC_STORAGE_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{

/**
\brief The static storage type

\ingroup fcpptmath
*/
template<
	typename T,
	fcppt::math::size_type N
>
using static_storage
=
std::array<
	T,
	N
>;

}
}

#endif
