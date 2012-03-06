//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_DETAIL_PRINT_HPP_INCLUDED
#define FCPPT_MPL_DETAIL_PRINT_HPP_INCLUDED

#include <fcppt/io/ostream.hpp>
#include <fcppt/mpl/for_each.hpp>
#include <fcppt/mpl/detail/print_function.hpp>
#include <fcppt/mpl/detail/print_one.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/back.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/pop_back.hpp>
#include <boost/utility/enable_if.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace mpl
{
namespace detail
{

template<
	typename Sequence
>
typename boost::enable_if<
	boost::mpl::empty<
		Sequence
	>,
	void
>::type
print(
	fcppt::io::ostream &
)
{
}

template<
	typename Sequence
>
typename boost::disable_if<
	boost::mpl::empty<
		Sequence
	>,
	void
>::type
print(
	fcppt::io::ostream &_stream
)
{
	fcppt::mpl::for_each<
		typename boost::mpl::pop_back<
			Sequence
		>::type
	>(
		fcppt::mpl::detail::print_function(
			_stream
		)
	);

	fcppt::mpl::detail::print_one<
		typename boost::mpl::back<
			Sequence
		>::type
	>(
		_stream
	);
}

}
}
}

#endif
