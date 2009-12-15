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


#include <fcppt/log/location.hpp>
#include <fcppt/text.hpp>
#include <boost/spirit/home/phoenix/core/argument.hpp>
#include <boost/spirit/home/phoenix/operator/arithmetic.hpp>
#include <numeric>

fcppt::log::location::location(
	fcppt::string const &initial_
)
:
	entries_(
		1,
		initial_
	)
{}

fcppt::log::location &
fcppt::log::location::operator +=(
	fcppt::string const &nstring_
)
{
	entries_.push_back(
		nstring_
	);

	return *this;
}

fcppt::log::location::const_iterator
fcppt::log::location::begin() const
{
	return entries_.begin();
}

fcppt::log::location::const_iterator
fcppt::log::location::end() const
{
	return entries_.end();
}

fcppt::string const
fcppt::log::location::string() const
{
	return
		std::accumulate(
			begin(),
			end(),
			fcppt::string(),
			boost::phoenix::arg_names::arg1
			+ fcppt::string(
				FCPPT_TEXT("::")
			)
			+ boost::phoenix::arg_names::arg2
		);
}

fcppt::log::location const
fcppt::log::operator +(
	location location_,
	string const &nstring_
)
{
	return location_ += nstring_;
}
