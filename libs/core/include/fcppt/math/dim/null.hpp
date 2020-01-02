//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DIM_NULL_HPP_INCLUDED
#define FCPPT_MATH_DIM_NULL_HPP_INCLUDED

#include <fcppt/math/detail/null_storage.hpp>
#include <fcppt/math/dim/is_dim.hpp>
#include <fcppt/math/dim/static.hpp>
#include <fcppt/type_traits/value_type.hpp>


namespace fcppt
{
namespace math
{
namespace dim
{

/**
\brief Returns the null dim

\ingroup fcpptmathdim
*/
template<
	typename Dim
>
fcppt::math::dim::static_<
	fcppt::type_traits::value_type<
		Dim
	>,
	Dim::static_size::value
>
null()
{
	static_assert(
		fcppt::math::dim::is_dim<
			Dim
		>::value,
		"Dim must be a dim"
	);

	typedef
	fcppt::math::dim::static_<
		fcppt::type_traits::value_type<
			Dim
		>,
		Dim::static_size::value
	>
	result_type;

	return
		result_type(
			fcppt::math::detail::null_storage<
				typename
				result_type::storage_type
			>()
		);
}

}
}
}

#endif
