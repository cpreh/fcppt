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


#ifndef SGE_CHRONO_DURATION_DECL_HPP_INCLUDED
#define SGE_CHRONO_DURATION_DECL_HPP_INCLUDED

#include <sge/chrono/duration_fwd.hpp>
#include <sge/chrono/is_duration.hpp>
#include <sge/ratio.hpp>
#include <boost/static_assert.hpp>

namespace sge
{
namespace chrono
{

template<
	typename Rep,
	typename Period
>
class duration {
public:
	BOOST_STATIC_ASSERT(
		!is_duration<
			Rep
		>::value
	);

	BOOST_STATIC_ASSERT(
		is_ratio<
			Period
		>::value
	);

	BOOST_STATIC_ASSERT(
		Period::num > 0
	);

	typedef Rep rep;
	typedef Period period;

	duration();

	template<
		typename Rep2
	>
	explicit duration(
		Rep2 const &
	);

	template<
		typename Rep2,
		typename Period2
	>
	duration(
		duration<
			Rep2,
			Period2
		> const &
	);

	~duration();

	duration(
		duration const &
	);

	duration &
	operator =(
		duration const &
	);

	rep
	count() const;

	duration
	operator +() const;

	duration
	operator -() const;

	duration &
	operator ++();

	duration
	operator ++(int);

	duration &
	operator --();

	duration
	operator --(int);

	duration &
	operator +=(
		duration const &
	);

	duration &
	operator -=(
		duration const &
	);

	duration &
	operator *=(
		rep const &
	);

	duration &
	operator /=(
		rep const &
	);

	static duration
	zero();

	static duration
	min();

	static duration
	max();
private:
	rep rep_;
};

}
}

#endif
