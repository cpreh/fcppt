//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_DETAIL_STATIC_STORAGE_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_DETAIL_STATIC_STORAGE_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/static_storage.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{
namespace detail
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename T,
	size_type N,
	size_type M
>
struct static_storage
:
math::detail::static_storage<
	T,
	N * M
>
{
};

FCPPT_PP_POP_WARNING

}
}
}
}

#endif
