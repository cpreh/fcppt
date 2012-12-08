//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_HAS_DIM_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_HAS_DIM_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/dim_matches.hpp>
#include <fcppt/math/vector/object_fwd.hpp>
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
namespace vector
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

/**
\brief Metafunction to check the dimension of a static vector
*/
template<
	typename Vector,
	fcppt::math::size_type Dim
>
struct has_dim
:
std::false_type
{
};

/// \cond FCPPT_DOXYGEN_DEBUG
template<
	typename T,
	typename N,
	typename S,
	fcppt::math::size_type Dim
>
struct has_dim<
	fcppt::math::vector::object<
		T,
		N,
		S
	>,
	Dim
>
:
fcppt::math::detail::dim_matches<
	Dim,
	N::value
>
{
};
/// \endcond

FCPPT_PP_POP_WARNING

}
}
}

#endif
