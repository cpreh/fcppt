//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_ENUM_ITERATOR_BASE_HPP_INCLUDED
#define FCPPT_DETAIL_ENUM_ITERATOR_BASE_HPP_INCLUDED

#include <fcppt/enum_iterator_fwd.hpp>
#include <fcppt/enum_size_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/iterator/iterator_facade.hpp>
#include <iterator>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace detail
{

template<
	typename Enum
>
using
enum_iterator_base
=
boost::iterator_facade<
	fcppt::enum_iterator<
		Enum
	>,
	Enum,
	std::forward_iterator_tag,
	Enum,
	typename
	std::make_signed<
		typename
		fcppt::enum_size_type<
			Enum
		>::type
	>::type
>;

}
}

#endif
