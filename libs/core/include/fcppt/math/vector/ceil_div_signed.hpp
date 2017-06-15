//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_CEIL_DIV_SIGNED_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_CEIL_DIV_SIGNED_HPP_INCLUDED

#include <fcppt/math/ceil_div_signed.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/vector/map.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace vector
{

/**
\brief Division rounded up for signed vectors

\ingroup fcpptmathvector
*/
template<
	typename T,
	fcppt::math::size_type N,
	typename S
>
fcppt::math::vector::static_<
	T,
	N
>
ceil_div_signed(
	fcppt::math::vector::object<
		T,
		N,
		S
	> const _vector,
	T const _factor
)
{
	static_assert(
		std::is_signed<
			T
		>::value,
		"T must be signed"
	);

	return
		fcppt::math::vector::map<
			T,
			N
		>(
			_vector,
			[
				_factor
			](
				T const _value
			)
			{
				return
					fcppt::math::ceil_div_signed(
						_value,
						_factor
					);
			}
		);
}

}
}
}

#endif
