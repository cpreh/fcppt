//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VERSION_INTEGRAL_C_HPP_INCLUDED
#define FCPPT_VERSION_INTEGRAL_C_HPP_INCLUDED

#include <fcppt/version_int.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief An integral constant for a version component

\ingroup fcpptvarious
*/
template<
	fcppt::version_int Value
>
using version_integral_c
=
std::integral_constant<
	fcppt::version_int,
	Value
>;

}

#endif
