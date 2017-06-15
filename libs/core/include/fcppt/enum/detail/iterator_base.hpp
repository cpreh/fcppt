//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ENUM_DETAIL_ITERATOR_BASE_HPP_INCLUDED
#define FCPPT_ENUM_DETAIL_ITERATOR_BASE_HPP_INCLUDED

#include <fcppt/enum/iterator_fwd.hpp>
#include <fcppt/enum/size_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/iterator/iterator_facade.hpp>
#include <iterator>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace enum_
{
namespace detail
{

template<
	typename Enum
>
using
iterator_base
=
boost::iterator_facade<
	fcppt::enum_::iterator<
		Enum
	>,
	Enum,
	std::forward_iterator_tag,
	Enum,
	typename
	std::make_signed<
		fcppt::enum_::size_type<
			Enum
		>
	>::type
>;

}
}
}

#endif
