//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_IS_STATIC_SIZE_HPP_INCLUDED
#define FCPPT_MATH_IS_STATIC_SIZE_HPP_INCLUDED

#include <fcppt/math/is_dynamic_size.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/not.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

/**
\brief A metafunction that checks if T specifies a static size
\ingroup fcpptmath
*/
template<
	typename T
>
struct is_static_size
:
boost::mpl::not_<
	fcppt::math::is_dynamic_size<
		T
	>
>
{};

FCPPT_PP_POP_WARNING

}
}

#endif
