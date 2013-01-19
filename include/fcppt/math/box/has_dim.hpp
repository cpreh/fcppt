//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_HAS_DIM_HPP_INCLUDED
#define FCPPT_MATH_BOX_HAS_DIM_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/box/object_fwd.hpp>
#include <fcppt/math/detail/dim_matches.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace box
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

/**
\brief Metafunction to check the dimension of a box
*/
template
<
	typename Box,
	size_type Dim
>
struct has_dim
:
std::false_type
{};

/// \cond FCPPT_DOXYGEN_DEBUG
template<
	typename T,
	size_type N,
	size_type Dim
>
struct has_dim<
	fcppt::math::box::object<
		T,
		N
	>,
	Dim
>
:
fcppt::math::detail::dim_matches<
	Dim,
	N
>
{};
/// \endcond

FCPPT_PP_POP_WARNING

}
}
}

#endif
