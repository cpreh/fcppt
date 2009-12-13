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


#ifndef SGE_CONTAINER_PTR_EQUAL_HPP_INCLUDED
#define SGE_CONTAINER_PTR_EQUAL_HPP_INCLUDED

namespace sge
{
namespace container
{

template<
	typename Ptr
>
class ptr_equal {
public:
	typedef bool result_type;

	explicit ptr_equal(
		Ptr const p)
	:
		p(p)
	{}

	template<
		typename Val
	>
	bool operator()(
		Val const &val) const
	{
		return &val == p;
	}
private:
	Ptr p;
};

template<
	typename Ptr
>
ptr_equal<Ptr> const
make_ptr_equal(
	Ptr const p)
{
	return ptr_equal<Ptr>(p);
}

}
}

#endif
