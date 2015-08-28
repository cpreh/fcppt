//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DIM_HAS_DIM_HPP_INCLUDED
#define FCPPT_MATH_DIM_HAS_DIM_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/dim_matches.hpp>
#include <fcppt/math/dim/object_fwd.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>


namespace fcppt
{
namespace math
{
namespace dim
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

/**
\brief Metafunction to check the dimension of a static dim
*/
template<
	typename Dim,
	fcppt::math::size_type Size
>
struct has_dim;

/// \cond FCPPT_DOXYGEN_DEBUG
template<
	typename T,
	fcppt::math::size_type N,
	typename S,
	fcppt::math::size_type Size
>
struct has_dim<
	fcppt::math::dim::object<
		T,
		N,
		S
	>,
	Size
>
:
fcppt::math::detail::dim_matches<
	Size,
	N
>
{
};
/// \endcond

FCPPT_PP_POP_WARNING

}
}
}

#endif
