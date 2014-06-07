//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_IS_VECTOR_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_IS_VECTOR_HPP_INCLUDED

#include <fcppt/math/vector/object_decl.hpp>
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
\brief Metafunction to test if a type is a vector type
\ingroup fcpptmathvector
\tparam T The type to test against
*/
template
<
	typename T
>
struct is_vector
:
	boost::mpl::false_
{
};

/// \cond FCPPT_DOXYGEN_DEBUG
template
<
	typename T,
	typename N,
	typename S
>
struct is_vector
<
	fcppt::math::vector::object<
		T,
		N,
		S
	>
>
:
	boost::mpl::true_
{
};
/// \endcond

FCPPT_PP_POP_WARNING

}
}
}

#endif
