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


#include <fcppt/variant/object_impl.hpp>
#include <fcppt/variant/recursive.hpp>
#include <fcppt/variant/apply_binary.hpp>
#include <fcppt/variant/output.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <cstdlib>

namespace
{

struct visitor
{
	typedef void result_type;

	template<
		typename T1,
		typename T2
	>
	result_type
	operator()(
		T1 const &t1,
		T2 const &t2
	) const
	{
		fcppt::io::cout
			<< t1
			<< FCPPT_TEXT(' ')
			<< t2
			<< FCPPT_TEXT('\n');
	}
};

struct wrapper;

typedef fcppt::variant::object<
	boost::mpl::vector2<
		fcppt::variant::recursive<
			wrapper
		>,
		int
	>
> recursive_variant;

struct wrapper
{
	wrapper(
		recursive_variant const &member
	)
	:
		member(member)
	{}

	recursive_variant member;
};

}

int main()
try
{
	typedef fcppt::variant::object<
		boost::mpl::vector2<
			int,
			fcppt::string
		>
	> variant;

	variant v(
		fcppt::string(
			FCPPT_TEXT("blabla")
		)
	);

	variant u(
		42
	);

#if 0
	fcppt::variant::apply_binary(
		visitor(),
		v,
		u
	);

	recursive_variant rv(
		42
	);

	recursive_variant rrv((
		wrapper(
			rv
		)
	));

	fcppt::io::cout
		<< rrv
		<< FCPPT_TEXT('\n');
#endif
}
catch(
	fcppt::exception const &e
)
{
	fcppt::io::cerr
		<< e.string()
		<< FCPPT_TEXT('\n');
	
	return EXIT_FAILURE;
}
