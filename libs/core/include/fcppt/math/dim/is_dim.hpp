//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DIM_IS_DIM_HPP_INCLUDED
#define FCPPT_MATH_DIM_IS_DIM_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/dim/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace dim
{

/**
\brief Metafunction to test if a type is a dim type
\ingroup fcpptmathdim
\tparam T The type to test against
*/
template<
	typename T
>
struct is_dim
:
std::false_type
{
};

/// \cond FCPPT_DOXYGEN_DEBUG
template<
	typename T,
	fcppt::math::size_type N,
	typename S
>
struct is_dim<
	fcppt::math::dim::object<
		T,
		N,
		S
	>
>
:
std::true_type
{
};
/// \endcond

}
}
}

#endif
