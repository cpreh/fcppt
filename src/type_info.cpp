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


#include <fcppt/type_info.hpp>
#include <fcppt/type_name.hpp>
#include <fcppt/assert.hpp>

fcppt::type_info::type_info(
	std::type_info const &ti
)
:
	info_(&ti)
{
	FCPPT_ASSERT(info_);
}

bool
fcppt::type_info::before(
	type_info const &rhs
) const
{
	FCPPT_ASSERT(info_);

	return info_->before(*rhs.info_);
}

std::type_info const &
fcppt::type_info::get() const
{
	FCPPT_ASSERT(info_);

	return *info_;
}

fcppt::string const
fccpt::type_info::name() const
{
	FCPPT_ASSERT(info_);

	return type_name(*this);
}

bool
fcppt::operator==(
	type_info const &lhs,
	type_info const &rhs
)
{
	return lhs.get() == rhs.get();
}

bool fcppt::operator<(const type_info& lhs, const type_info& rhs)
{
	return lhs.before(rhs);
}

bool fcppt::operator!=(const type_info& lhs, const type_info& rhs)
{
	return !(lhs == rhs);
}

bool fcppt::operator>(const type_info& lhs, const type_info& rhs)
{
	return rhs < lhs;
}

bool fcppt::operator<=(const type_info& lhs, const type_info& rhs)
{
	return !(lhs > rhs);
}

bool fcppt::operator>=(const type_info& lhs, const type_info& rhs)
{
	return !(lhs < rhs);
}
