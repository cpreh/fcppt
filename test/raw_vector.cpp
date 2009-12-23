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


#include <fcppt/container/raw_vector_impl.hpp>
#include <fcppt/container/field_impl.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/text.hpp>
#include <vector>

int main()
{
	typedef fcppt::container::field<
		fcppt::container::raw_vector<
			bool
		>
	> field_vector;

	typedef std::vector<
		field_vector
	> vector_of_fields;

	vector_of_fields outer;

	for(
		unsigned i = 0;
		i < 100;
		++i
	)
	{
		field_vector test(
			field_vector::dim(
				4,
				1
			)
		);

		outer.push_back(
			test	
		);
	}

	fcppt::io::cout
		<< outer[42]
		<< FCPPT_TEXT('\n');
}
