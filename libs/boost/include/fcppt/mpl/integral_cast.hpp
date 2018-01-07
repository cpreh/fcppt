//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_INTEGRAL_CAST_HPP_INCLUDED
#define FCPPT_MPL_INTEGRAL_CAST_HPP_INCLUDED

#include <fcppt/mpl/integral_cast_tpl.hpp>


namespace fcppt
{
namespace mpl
{

/**
\brief Does an integral cast on an integral constant

\ingroup fcpptmpl

Casts \a Integral to an integral constant of type \a IntegralType. The cast is
done using \a Conv from fcppt.casts.

\tparam IntegralType An integral type to cast to

\tparam Conv A cast function from fcppt.casts

\tparam Integral An MPL integral constant to cast from
*/
template<
	typename IntegralType,
	typename Conv,
	typename Integral
>
using integral_cast
=
typename
fcppt::mpl::integral_cast_tpl<
	IntegralType,
	Conv,
	Integral
>::type;

}
}

#endif
