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


#include <fcppt/container/map_impl.hpp>
#include <fcppt/container/raw_vector_impl.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/assert.hpp>
#include <boost/foreach.hpp>
#include <map>

int main()
{
	typedef fcppt::container::map<
		std::map<
			int,
			fcppt::string
		>
	> map_type;

	map_type m;

	m.insert(
		42,
		FCPPT_TEXT("peter")
	);

	BOOST_FOREACH(
		map_type::const_reference r,
		m
	)
		fcppt::io::cout
			<< r.first
			<< FCPPT_TEXT(": ")
			<< r.second
			<< '\n';

	typedef fcppt::container::raw_vector<
		char
	> vector_type;

	std::string const test_string(
		"abcdefg"
	);

	vector_type vec;

	vec.reserve(42);

	vec.insert(
		vec.end(),
		test_string.begin(),
		test_string.end()
	);

	FCPPT_ASSERT(
		vec.size() == test_string.size()
	);

	vec.insert(
		vec.begin() + test_string.size() / 2,
		test_string.begin(),
		test_string.end()
	);

	fcppt::io::cout << vec.size() << '\n';
}
