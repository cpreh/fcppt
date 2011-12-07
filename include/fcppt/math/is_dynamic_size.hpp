//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_IS_DYNAMIC_SIZE_HPP_INCLUDED
#define FCPPT_MATH_IS_DYNAMIC_SIZE_HPP_INCLUDED

#include <fcppt/math/detail/dynamic_size.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/type_traits/is_same.hpp>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace math
{

/**
\brief A metafunction that checks if T specifies a dynamic size
\ingroup fcpptmath
*/
template<
	typename T
>
struct is_dynamic_size
:
boost::is_same<
	T,
	detail::dynamic_size
>
{};

}
}

#endif
