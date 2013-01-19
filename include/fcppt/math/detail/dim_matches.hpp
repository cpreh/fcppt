//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_DIM_MATCHES_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_DIM_MATCHES_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/bool.hpp>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace math
{
namespace detail
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	fcppt::math::size_type Desired,
	fcppt::math::size_type Current
>
struct dim_matches
:
	boost::mpl::bool_<
		Desired == Current
		|| Current == 0
	>
{};

FCPPT_PP_POP_WARNING

}
}
}

#endif
