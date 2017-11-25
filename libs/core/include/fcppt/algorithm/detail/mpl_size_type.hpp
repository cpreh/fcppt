//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_DETAIL_MPL_SIZE_TYPE_HPP_INCLUDED
#define FCPPT_ALGORITHM_DETAIL_MPL_SIZE_TYPE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/is_sequence.hpp>
#include <boost/mpl/size.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{
namespace detail
{

template<
	typename Type,
	typename Test = void
>
struct mpl_size_type
{
	typedef
	void
	type;
};

template<
	typename Type
>
struct mpl_size_type<
	Type,
	typename
	std::enable_if<
		boost::mpl::is_sequence<
			Type
		>::value
	>::type
>
{
	typedef
	typename
	boost::mpl::size<
		Type
	>::value_type
	type;
};

}
}
}

#endif
