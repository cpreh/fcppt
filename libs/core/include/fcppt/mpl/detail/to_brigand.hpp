//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_DETAIL_TO_BRIGAND_HPP_INCLUDED
#define FCPPT_MPL_DETAIL_TO_BRIGAND_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <brigand/sequences/back.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/next.hpp>
#include <boost/utility/enable_if.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace mpl
{
namespace detail
{

template<
	typename It,
	typename ItEnd,
	typename State,
	typename Enable = void
>
struct to_brigand;

template<
	typename It,
	typename ItEnd,
	typename State
>
struct to_brigand<
	It,
	ItEnd,
	State,
	typename
	boost::enable_if<
		std::is_same<
			It,
			ItEnd
		>
	>::type
>
{
	typedef
	State
	type;
};

template<
	typename It,
	typename ItEnd,
	typename State
>
struct to_brigand<
	It,
	ItEnd,
	State,
	typename
	boost::disable_if<
		std::is_same<
			It,
			ItEnd
		>
	>::type
>
{
	typedef
	typename
	fcppt::mpl::detail::to_brigand<
		typename
		boost::mpl::next<
			It
		>::type,
		ItEnd,
		::brigand::push_back<
			State,
			typename
			boost::mpl::deref<
				It
			>::type
		>
	>::type
	type;
};

}
}
}

#endif
