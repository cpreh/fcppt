//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_TO_ANGLE_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_TO_ANGLE_HPP_INCLUDED

#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/vector/arithmetic.hpp>
#include <fcppt/math/vector/atan2.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/math/vector/structure_cast.hpp>
#include <fcppt/math/detail/has_size.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_floating_point.hpp>
#include <boost/mpl/and.hpp>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace math
{
namespace vector
{

/// Calculates the angle between @a to and vector(1, 0)
/**
 * @tparam N must be 2
 * @return The angle if @a to is not the null vector, an empty optional otherwise
*/
template<
	typename Dest,
	typename T,
	typename N,
	typename S
>
typename boost::enable_if<
	boost::mpl::and_<
		boost::is_floating_point<
			Dest
		>,
		math::detail::has_size<
			N,
			2
		>
	>,
	fcppt::optional<
		Dest
	>
>::type
to_angle(
	basic<T, N, S> const &_to
)
{
	return
		vector::atan2(
			vector::structure_cast<
				typename vector::static_<
					Dest,
					N::value
				>::type
			>(
				_to
			)
		);
}

}
}
}

#endif
