//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_BRIGAND_FOUND_T_HPP_INCLUDED
#define FCPPT_BRIGAND_FOUND_T_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <brigand/algorithms/find.hpp>
#include <brigand/functions/lambda/apply.hpp>
#include <brigand/functions/lambda/bind.hpp>
#include <brigand/types/args.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace brigand
{

/**
\brief Checks if a sequence contains an element.

\ingroup fcpptbrigand

Checks if \a Sequence contains \a Type.
*/
template<
	typename Sequence,
	typename Type
>
using
found_t
=
::brigand::found<
	Sequence,
	::brigand::bind<
		std::is_same,
		::brigand::pin<
			Type
		>,
		::brigand::_1
	>
>;

}
}

#endif
