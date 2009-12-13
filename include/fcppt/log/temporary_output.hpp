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


#ifndef SGE_LOG_TEMPORARY_OUTPUT_HPP_INCLUDED
#define SGE_LOG_TEMPORARY_OUTPUT_HPP_INCLUDED

#include <sge/log/temporary_output_fwd.hpp>
#include <sge/log/output_helper.hpp>
#include <sge/export.hpp>
#include <sge/shared_ptr.hpp>
#include <sge/ostringstream.hpp>
#include <sge/string.hpp>
#include <ostream>

namespace sge
{
namespace log
{

class temporary_output {
public:
	SGE_SYMBOL temporary_output();

	SGE_SYMBOL string const
	result() const;
private:
	shared_ptr<
		ostringstream
	> os;

	template<
		typename T
	>
	friend temporary_output const
	operator<<(
		temporary_output const &,
		T const &
	);
};

template<
	typename T
>
temporary_output const
operator<<(
	output_helper const &,
	T const &t
)
{
	return temporary_output() << t;
}

template<
	typename T
>
temporary_output const
operator<<(
	temporary_output const &s,
	T const &t
)
{
	temporary_output n(s);
	*n.os << t;
	return n;
}

}
}

#endif
