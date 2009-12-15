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


#ifndef FCPPT_RANDOM_UNIFORM_HPP_INCLUDED
#define FCPPT_RANDOM_UNIFORM_HPP_INCLUDED

#include <fcppt/random/default_generator.hpp>
#include <fcppt/random/uniform_distribution.hpp>
#include <fcppt/chrono/high_resolution_clock.hpp>
#include <fcppt/chrono/time_point_impl.hpp>
#include <fcppt/chrono/duration_impl.hpp>
#include <tr1/random>

namespace fcppt
{
namespace random
{

template<
	typename T
>
class range;

template<
	typename T,
	typename Generator = default_generator
>
class uniform {
	typedef typename uniform_distribution<
		T
	>::type range_type;
public:
	explicit uniform(
		range<T> const &range)
	:
		variate(
			Generator(
				static_cast<
					typename Generator::result_type
				>(
					fcppt::chrono::high_resolution_clock::now().time_since_epoch().count()
				)
			),
			range_type(
				range.first(),
				range.last()
			)
		)
	{}

	uniform(
		range<T> const &range,
		Generator const &gen)
	:
		variate(
			gen,
			range_type(
				range.first(),
				range.last()
			)
		)
	{}

	T operator()()
	{
		return variate();
	}
private:
	typedef typename std::tr1::variate_generator<
		Generator,
		range_type
	> variate_type;

	variate_type variate;
};

}
}

#endif
