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


#include <fcppt/random/actor/normalized.hpp>
#include <fcppt/random/actor/element.hpp>
#include <fcppt/random/inclusive_range.hpp>
#include <fcppt/tr1/functional.hpp>
#include <fcppt/exception.hpp>
#include <fcppt/text.hpp>
#include <fcppt/format.hpp>
#include <boost/foreach.hpp>
#include <numeric>
#include <functional>

fcppt::random::actor::normalized::normalized(
	container const &elements
)
:
	elements(elements),
	rng(
		random::make_inclusive_range(
			static_cast<float_type>(0),
			std::accumulate(
				elements.begin(),
				elements.end(),
				static_cast<float_type>(0),
				std::tr1::bind(
					std::plus<
						float_type
					>(),
					std::tr1::placeholders::_1,
					std::tr1::bind(
						&element::prob,
						std::tr1::placeholders::_2
					)
				)
			)
		)
	)
{
	if(elements.empty())
		throw exception(
			FCPPT_TEXT("actor::normalized: elements may not be empty!")
		);
}

fcppt::random::actor::normalized::~normalized()
{}

void
fcppt::random::actor::normalized::operator()()
{
	float_type const val(
		rng()
	);

	float_type cur(
		val
	);

	BOOST_FOREACH(
		container::const_reference ref,
		elements
	)
	{
		if(cur <= ref.prob())
		{
			ref.callback()();
			return;
		}
		cur -= ref.prob();
	}

	throw exception(
		(fcppt::format(
			FCPPT_TEXT("random::actor::normalized: nothing matched! Return value was %1% and is now %2%!")
		) % val % cur).str()
	);
}
