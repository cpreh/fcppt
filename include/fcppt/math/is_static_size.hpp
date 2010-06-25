//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_IS_STATIC_SIZE_HPP_INCLUDED
#define FCPPT_MATH_IS_STATIC_SIZE_HPP_INCLUDED

#include <fcppt/math/is_dynamic_size.hpp>
#include <boost/mpl/not.hpp>

namespace fcppt
{
namespace math
{

/// A metafunction that checks if T specifies a static size
template<
	typename T
>
struct is_static_size
:
boost::mpl::not_<
	math::is_dynamic_size<
		T
	>
>
{};

}
}

#endif
