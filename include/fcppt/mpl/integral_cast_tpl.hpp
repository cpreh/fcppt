//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_INTEGRAL_CAST_TPL_HPP_INCLUDED
#define FCPPT_MPL_INTEGRAL_CAST_TPL_HPP_INCLUDED

#include <fcppt/cast/apply.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace mpl
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

/**
\brief Does an integral cast on an integral constant

\ingroup fcpptmpl
*/
template<
	typename IntegralType,
	typename Conv,
	typename Integral
>
struct integral_cast_tpl
:
std::integral_constant<
	IntegralType,
	fcppt::cast::apply<
		Conv,
		IntegralType
	>(
		Integral::value
	)
>
{
};

}
}

#endif
