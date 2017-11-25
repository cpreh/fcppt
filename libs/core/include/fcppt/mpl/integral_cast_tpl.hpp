//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_INTEGRAL_CAST_TPL_HPP_INCLUDED
#define FCPPT_MPL_INTEGRAL_CAST_TPL_HPP_INCLUDED

#include <fcppt/mpl/detail/integral_cast_value.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace mpl
{

/**
\brief Does an integral cast on an integral constant

\ingroup fcpptmpl

\see fcppt::mpl::integral_cast
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
	fcppt::mpl::detail::integral_cast_value<
		IntegralType,
		Conv,
		Integral
	>::value
>
{
};

}
}

#endif
