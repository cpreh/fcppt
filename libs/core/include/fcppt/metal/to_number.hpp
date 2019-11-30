//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_METAL_TO_NUMBER_HPP_INCLUDED
#define FCPPT_METAL_TO_NUMBER_HPP_INCLUDED

#include <fcppt/type_traits/safe_integral_cast.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal/number/number.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace metal
{

/**
\brief Converts a std::integral_constant to a metal::number.

\ingroup fcpptmetal

Let <code>Src=std::integral_constant<T,n></code>.
The result will be <code>metal::number<n></code>.
This only works if <code>n</code> can be converted without loss.

\tparam Src Must be a std::integral_constant.
*/
template<
	typename Src
>
using
to_number
=
fcppt::type_traits::safe_integral_cast<
	::metal::int_,
	Src
>;

}
}

#endif
