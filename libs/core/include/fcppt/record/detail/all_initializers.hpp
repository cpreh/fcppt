//          Copyright Carl Philipp Reh 2014 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_DETAIL_ALL_INITIALIZERS_HPP_INCLUDED
#define FCPPT_RECORD_DETAIL_ALL_INITIALIZERS_HPP_INCLUDED

#include <fcppt/mpl/all_of.hpp>
#include <fcppt/record/detail/contains_initializer.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/placeholders.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace record
{
namespace detail
{

template<
	typename InitTypes,
	typename Args
>
using all_initializers
=
fcppt::mpl::all_of<
	InitTypes,
	fcppt::record::detail::contains_initializer<
		Args,
		boost::mpl::_1
	>
>;

}
}
}

#endif
