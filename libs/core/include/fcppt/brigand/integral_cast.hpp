//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_BRIGAND_INTEGRAL_CAST_HPP_INCLUDED
#define FCPPT_BRIGAND_INTEGRAL_CAST_HPP_INCLUDED

#include <fcppt/brigand/detail/integral_cast_value.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace brigand
{

/**
\brief Does an integral cast on an integral constant

\ingroup fcpptbrigand

Casts \a Integral to an integral constant of type \a IntegralType. The cast is
done using \a Conv from fcppt.casts.

\snippet brigand/various.cpp brigand_integral_cast

\tparam IntegralType An integral type to cast to

\tparam Conv A cast function from fcppt.casts

\tparam Integral An BRIGAND integral constant to cast from
*/
template<
	typename IntegralType,
	typename Conv,
	typename Integral
>
using
integral_cast
=
std::integral_constant<
	IntegralType,
	fcppt::brigand::detail::integral_cast_value<
		IntegralType,
		Conv,
		Integral
	>::value
>;

}
}

#endif
