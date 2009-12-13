/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2009 Carl Philipp Reh (sefi@s-e-f-i.de)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/


#ifndef SGE_CHRONO_DURATION_CAST_HPP_INCLUDED
#define SGE_CHRONO_DURATION_CAST_HPP_INCLUDED

#include <sge/chrono/common_type.hpp>
#include <sge/chrono/duration_impl.hpp>
#include <sge/ratio.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/utility/enable_if.hpp>

namespace sge
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
typename boost::enable_if_c<
	ratio_divide<
		Period,
		typename ToDuration::period
	>::type::num == 1,
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
				ratio_divide<
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
typename boost::enable_if_c<
	ratio_divide<
		Period,
		typename ToDuration::period
	>::type::den == 1,
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
				ratio_divide<
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
	ratio_divide<
		Period,
		typename ToDuration::period
	>::type::num != 1
	&&
	ratio_divide<
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

	typedef typename ratio_divide<
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

