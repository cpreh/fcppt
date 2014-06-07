//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_INTEGRAL_CAST_HPP_INCLUDED
#define FCPPT_MPL_INTEGRAL_CAST_HPP_INCLUDED

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
\brief Does an integral cast on compile an integral constant

\ingroup fcpptmpl

Casts \a Integral to the correspoding type using \a IntegralType. Equivalent to
<code>std::integral_constant<IntegralType,
static_cast<IntegralType>(Integral::value)</code>.

\snippet mpl/various.cpp mpl_integral_cast

\tparam IntegralType An integral type to cast to

\tparam Integral An MPL integral constant to cast from
*/
template<
	typename IntegralType,
	typename Integral
>
struct integral_cast
:
std::integral_constant<
	IntegralType,
	static_cast<
		IntegralType
	>(
		Integral::value
	)
>
{
};

FCPPT_PP_POP_WARNING

}
}

#endif
