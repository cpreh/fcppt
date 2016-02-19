//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_DETAIL_PRINT_HPP_INCLUDED
#define FCPPT_MPL_DETAIL_PRINT_HPP_INCLUDED

#include <fcppt/decltype_sink.hpp>
#include <fcppt/tag_type.hpp>
#include <fcppt/text.hpp>
#include <fcppt/io/ostream.hpp>
#include <fcppt/mpl/for_each.hpp>
#include <fcppt/mpl/detail/print_one.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/back.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/pop_back.hpp>
#include <ostream>
#include <type_traits>
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
typename
std::enable_if<
	boost::mpl::empty<
		Sequence
	>::value,
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
typename
std::enable_if<
	!boost::mpl::empty<
		Sequence
	>::value,
	void
>::type
print(
	fcppt::io::ostream &_stream
)
{
	fcppt::mpl::for_each<
		typename
		boost::mpl::pop_back<
			Sequence
		>::type
	>(
		[
			&_stream
		](
			auto const _type
		)
		{
			fcppt::mpl::detail::print_one<
				fcppt::tag_type<
					FCPPT_DECLTYPE_SINK(
						_type
					)
				>
			>(
				_stream
			);

			_stream
				<< FCPPT_TEXT(',');
		}
	);

	fcppt::mpl::detail::print_one<
		typename
		boost::mpl::back<
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
