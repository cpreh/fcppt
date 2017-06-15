//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DETAIL_NOTHROW_MOVE_CONSTRUCTIBLE_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_NOTHROW_MOVE_CONSTRUCTIBLE_HPP_INCLUDED

#include <fcppt/mpl/all_of.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/placeholders.hpp>
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
fcppt::mpl::all_of<
	Types,
	std::is_nothrow_move_constructible<
		boost::mpl::_1
	>
>;

}
}
}

#endif
