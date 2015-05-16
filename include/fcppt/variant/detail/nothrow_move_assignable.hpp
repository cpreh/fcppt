//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DETAIL_NOTHROW_MOVE_ASSIGNABLE_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_NOTHROW_MOVE_ASSIGNABLE_HPP_INCLUDED

#include <fcppt/mpl/all_of.hpp>
#include <fcppt/variant/detail/nothrow_move_constructible.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/and.hpp>
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
nothrow_move_assignable
=
boost::mpl::and_<
	fcppt::variant::detail::nothrow_move_constructible<
		Types
	>,
	fcppt::mpl::all_of<
		Types,
		std::is_nothrow_move_assignable<
			boost::mpl::_1
		>
	>
>;

}
}
}

#endif
