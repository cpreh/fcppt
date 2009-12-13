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


#ifndef SGE_OPTIONAL_DECL_HPP_INCLUDED
#define SGE_OPTIONAL_DECL_HPP_INCLUDED

#include <sge/optional_fwd.hpp>
#include <sge/safe_bool.hpp>
#include <sge/alignment/array.hpp>
#include <boost/type_traits/alignment_of.hpp>

namespace sge
{

template<
	typename T
>
class optional {
	SGE_SAFE_BOOL(optional)
public:
	typedef T value_type;
	typedef T &reference;
	typedef T const &const_reference;
	typedef T *pointer;
	typedef T const *const_pointer;

	optional();

	// intentionally not explicit
	optional(
		const_reference);

	optional(
		optional const &);

	optional &
	operator=(
		optional const &);

	optional &
	operator=(
		const_reference);

	~optional();

	reference operator*();
	const_reference operator*() const;

	pointer operator->();
	const_pointer operator->() const;

	void reset();
private:
	bool boolean_test() const;

	pointer
	construct(
		const_reference);

	pointer
	construct(
		optional const &);

	void destroy();

	typedef typename alignment::array<
		unsigned char,
		sizeof(T),
		boost::alignment_of<
			T
		>::value
	>::type storage_type;

	storage_type storage_;
	pointer data_;
};

}

#endif
