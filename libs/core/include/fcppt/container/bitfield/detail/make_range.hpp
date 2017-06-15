//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_BITFIELD_DETAIL_MAKE_RANGE_HPP_INCLUDED
#define FCPPT_CONTAINER_BITFIELD_DETAIL_MAKE_RANGE_HPP_INCLUDED

#include <fcppt/int_range_impl.hpp>
#include <fcppt/make_int_range_count.hpp>
#include <fcppt/enum/make_range.hpp>
#include <fcppt/enum/range_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace bitfield
{
namespace detail
{

template<
	typename Element,
	typename Size
>
inline
typename
boost::enable_if<
	std::is_enum<
		Element
	>,
	fcppt::enum_::range<
		Element
	>
>::type
make_range()
{
	return
		fcppt::enum_::make_range<
			Element
		>();
}

template<
	typename Element,
	typename Size
>
inline
typename
boost::enable_if<
	std::is_integral<
		Element
	>,
	fcppt::int_range<
		Element
	>
>::type
make_range()
{
	return
		fcppt::make_int_range_count<
			Element
		>(
			Size::value
		);
}

}
}
}
}

#endif
