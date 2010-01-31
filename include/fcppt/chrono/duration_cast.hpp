//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CHRONO_DURATION_CAST_HPP_INCLUDED
#define FCPPT_CHRONO_DURATION_CAST_HPP_INCLUDED

#include <fcppt/chrono/common_type.hpp>
#include <fcppt/chrono/duration_impl.hpp>
#include <fcppt/ratio/divide.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/not.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/utility/enable_if.hpp>

namespace fcppt
{
namespace chrono
{

template<
	typename ToDuration,
	typename Rep,
	typename Period
>
typename boost::enable_if<
	boost::is_same<
		typename ToDuration::period,
		Period
	>,
	ToDuration
>::type
duration_cast(
	duration<
		Rep,
		Period
	> const &d
)
{
	return ToDuration(
		static_cast<
			typename ToDuration::rep
		>(
			d.count()
		)
	);
}

template<
	typename ToDuration,
	typename Rep,
	typename Period
>
typename boost::enable_if<
	boost::mpl::and_<
		boost::mpl::bool_<
			ratio::divide<
				Period,
				typename ToDuration::period
			>::type::num == 1
		>,
		boost::mpl::not_<
			boost::is_same<
				typename ToDuration::period,
				Period
			>
		>
	>,
	ToDuration
>::type
duration_cast(
	duration<
		Rep,
		Period
	> const &d
)
{
	typedef typename common_type<
		typename ToDuration::rep,
		Rep
	>::type middle;

	return ToDuration(
		static_cast<
			typename ToDuration::rep
		>(
			static_cast<
				middle
			>(
				d.count()
			)
			/
			static_cast<
				middle
			>(
				ratio::divide<
					Period,
					typename ToDuration::period
				>::type::den
			)
		)
	);
}

template<
	typename ToDuration,
	typename Rep,
	typename Period
>
typename boost::enable_if<
	boost::mpl::and_<
		boost::mpl::bool_<
			ratio::divide<
				Period,
				typename ToDuration::period
			>::type::den == 1
		>,
		boost::mpl::not_<
			boost::is_same<
				typename ToDuration::period,
				Period
			>
		>
	>,
	ToDuration
>::type
duration_cast(
	duration<
		Rep,
		Period
	> const &d
)
{
	typedef typename common_type<
		typename ToDuration::rep,
		Rep
	>::type middle;

	return ToDuration(
		static_cast<
			typename ToDuration::rep
		>(
			static_cast<
				middle
			>(
				d.count()
			)
			*
			static_cast<
				middle
			>(
				ratio::divide<
					Period,
					typename ToDuration::period
				>::type::num
			)
		)
	);
}

template<
	typename ToDuration,
	typename Rep,
	typename Period
>
typename boost::enable_if_c<
	ratio::divide<
		Period,
		typename ToDuration::period
	>::type::num != 1
	&&
	ratio::divide<
		Period,
		typename ToDuration::period
	>::type::den != 1,
	ToDuration
>::type
duration_cast(
	duration<
		Rep,
		Period
	> const &d
)
{
	typedef typename common_type<
		typename ToDuration::rep,
		Rep
	>::type middle;

	typedef typename ratio::divide<
		Period,
		typename ToDuration::period
	>::type div;

	return ToDuration(
		static_cast<
			typename ToDuration::rep
		>(
			static_cast<
				middle
			>(
				d.count()
			)
			*
			static_cast<
				middle
			>(
				div::num
			)
			/
			static_cast<
				middle
			>(
				div::den
			)
		)
	);
}

}
}

#endif

