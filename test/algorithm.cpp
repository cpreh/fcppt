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


#include <fcppt/algorithm/copy_n.hpp>
#include <fcppt/algorithm/append.hpp>
#include <fcppt/algorithm/find_exn.hpp>
#include <fcppt/container/raw_vector_impl.hpp>
#include <string>
#include <ostream>
#include <iostream>

int main()
{
	typedef fcppt::container::raw_vector<
		unsigned char
	> vector_type;

	std::string const str("test");

	vector_type a(str.size());

	fcppt::algorithm::copy_n(str.data(), str.size(), a.data());

	a.push_back(' ');

	vector_type b(a);

	fcppt::algorithm::append(
		a,
		b
	);

	fcppt::algorithm::find_exn(
		str.begin(),
		str.end(),
		't'
	);

	std::cout << std::string(a.begin(), a.end()) << '\n';
}
