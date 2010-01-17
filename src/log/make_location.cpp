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


#include <fcppt/log/make_location.hpp>
#include <fcppt/log/exception.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/next_prior.hpp>
#include <vector>

fcppt::log::location const
fcppt::log::make_location(
	string const &name,
	char_type const delim
)
{
	typedef std::vector<
		string
	> vector_type;

	vector_type elements;

	boost::algorithm::split(
		elements,
		name,
		boost::is_any_of(
			string(
				1u,
				delim
			)
		)
	);

	if(
		elements.empty()
	)
		throw fcppt::log::exception(
			FCPPT_TEXT("Invalid log location \"")
			+ name
			+ FCPPT_TEXT("\". It has no elements after split.")
		);
	
	location ret(
		elements[0]
	);

	for(
		vector_type::const_iterator it(
			boost::next(
				elements.begin()
			)
		);
		it != elements.end();
		++it
	)
		ret += *it;
	
	return ret;
}
