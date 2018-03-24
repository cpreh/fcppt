//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_AT_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_AT_HPP_INCLUDED

#include <fcppt/container/to_reference_type.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/checked_access.hpp>
#include <fcppt/math/vector/is_vector.hpp>
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
\brief Access an element using a compile-time constant

\ingroup fcpptmathvector

\tparam Vector Must be an \link fcppt::math::vector::object\endlink.
*/
template<
	fcppt::math::size_type Index,
	typename Vector
>
inline
fcppt::container::to_reference_type<
	std::remove_reference_t<
		Vector
	>
>
at(
	Vector &_value
)
{
	static_assert(
		fcppt::math::vector::is_vector<
			std::remove_cv_t<
				Vector
			>
		>::value,
		"Vector must be a vector"
	);

	return
		fcppt::math::detail::checked_access<
			Index
		>(
			_value
		);
}

}
}
}

#endif
