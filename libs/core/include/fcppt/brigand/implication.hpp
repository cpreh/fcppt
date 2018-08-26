//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_BRIGAND_IMPLICATION_HPP_INCLUDED
#define FCPPT_BRIGAND_IMPLICATION_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <brigand/functions/logical/not.hpp>
#include <brigand/functions/logical/or.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace brigand
{

/**
\brief The implication function: \a Left -> \a Right

\ingroup fcpptbrigand

Calculates the implication of \a Left and \a Right. Equal to (not \a Left) or
\a Right)

\snippet brigand/various.cpp brigand_implication

\tparam Left A boolean expression

\tparam Right A boolean expression
*/
template<
	typename Left,
	typename Right
>
using
implication
=
::brigand::or_<
	::brigand::not_<
		Left
	>,
	Right
>;

}
}

#endif
