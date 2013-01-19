//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_STATIC_SIZE_HPP_INCLUDED
#define FCPPT_MATH_STATIC_SIZE_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/integral_c.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

/**
\brief An mpl integral_c for math::size_type
*/
template<
	fcppt::math::size_type N
>
struct static_size
:
boost::mpl::integral_c<
	fcppt::math::size_type,
	N
>
{
};

FCPPT_PP_POP_WARNING

}
}

#endif
