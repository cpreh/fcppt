//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DETAIL_NOTHROW_MOVE_CONSTRUCTIBLE_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_NOTHROW_MOVE_CONSTRUCTIBLE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <brigand/algorithms/all.hpp>
#include <brigand/types/args.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace variant
{
namespace detail
{

template<
	typename Types
>
using
nothrow_move_constructible
=
::brigand::all<
	Types,
	std::is_nothrow_move_constructible<
		::brigand::_1
	>
>;

}
}
}

#endif
