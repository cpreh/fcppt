//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_ATAN2_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_ATAN2_HPP_INCLUDED

#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/math/vector/is_null.hpp>
#include <fcppt/math/detail/has_size.hpp>
#include <fcppt/optional_impl.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_floating_point.hpp>
#include <boost/mpl/and.hpp>
#include <cmath>

namespace fcppt
{
namespace math
{
namespace vector
{

template<
	typename T,
	typename N,
	typename S
>
inline typename boost::enable_if<
	boost::mpl::and_<
		boost::is_floating_point<
			T
		>,
		math::detail::has_size<
			N,
			2
		>
	>,
	optional<T>
>::type
atan2(
	basic<T, N, S> const &v)
{
	return is_null(v)
		? optional<T>()
		: std::atan2(v.y(), v.x());
}

}
}
}

#endif
