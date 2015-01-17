//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_INT_ITERATOR_BASE_HPP_INCLUDED
#define FCPPT_DETAIL_INT_ITERATOR_BASE_HPP_INCLUDED

#include <fcppt/int_iterator_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/iterator/iterator_facade.hpp>
#include <iterator>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace detail
{

template<
	typename Int
>
using
int_iterator_base
=
boost::iterator_facade<
	fcppt::int_iterator<
		Int
	>,
	Int,
	std::forward_iterator_tag,
	Int
>;

}
}

#endif
