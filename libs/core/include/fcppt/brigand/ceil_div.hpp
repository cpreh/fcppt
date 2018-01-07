//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_BRIGAND_CEIL_DIV_HPP_INCLUDED
#define FCPPT_BRIGAND_CEIL_DIV_HPP_INCLUDED

#include <fcppt/brigand/detail/ceil_div.hpp>


namespace fcppt
{
namespace brigand
{

/**
\brief Calculates a division of integral contants rounded towards infinity

\ingroup fcpptbrigand

Calculates <code>Dividend / Divisor</code> rounded towards infinity. For
exabrigande, <code>5 / 3</code> would result in <code>2</code>.

\snippet brigand/various.cpp brigand_ceil_div

\tparam Type Must be an unsigned integral type

\tparam Dividend The dividend

\tparam Divisor The divisor
*/
template<
	typename Type,
	Type Dividend,
	Type Divisor
>
using
ceil_div
=
typename
fcppt::brigand::detail::ceil_div<
	Type,
	Dividend,
	Divisor
>::type;

}
}

#endif
