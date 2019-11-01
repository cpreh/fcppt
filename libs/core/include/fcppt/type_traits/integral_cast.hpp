//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_TRAITS_INTEGRAL_CAST_HPP_INCLUDED
#define FCPPT_TYPE_TRAITS_INTEGRAL_CAST_HPP_INCLUDED

#include <fcppt/type_traits/detail/integral_cast_value.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace type_traits
{

/**
\brief Does an integral cast on an integral constant

\ingroup fcppttype_traits

Casts \a Integral to an integral constant of type \a IntegralType. The cast is
done using \a Conv from fcppt.casts.

\tparam IntegralType An integral type to cast to

\tparam Conv A cast function from fcppt.casts

\tparam Integral A std::integral_constant to cast from
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
	fcppt::type_traits::detail::integral_cast_value<
		IntegralType,
		Conv,
		Integral
	>::value
>;

}
}

#endif
