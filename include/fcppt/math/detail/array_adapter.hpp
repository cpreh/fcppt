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


#ifndef FCPPT_MATH_DETAIL_ARRAY_ADAPTER_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_ARRAY_ADAPTER_HPP_INCLUDED

#define FCPPT_MATH_DETAIL_ARRAY_ADAPTER(name)\
	reference \
	at(\
		size_type\
	);\
\
	const_reference \
	at(\
		size_type\
	) const;\
\
	pointer \
	data_end();\
\
	const_pointer \
	data_end() const;\
\
	iterator \
	begin();\
\
	const_iterator \
	begin() const;\
\
	iterator \
	end();\
\
	const_iterator \
	end() const;\
\
	reverse_iterator \
	rbegin();\
\
	const_reverse_iterator \
	rbegin() const;\
\
	reverse_iterator \
	rend();\
\
	const_reverse_iterator \
	rend() const;\
\
	reference \
	back();\
\
	const_reference \
	back() const;\
\
	reference \
	front();\
\
	const_reference \
	front() const;\
\
	bool \
	empty() const;\
\
	bool \
	operator==(\
		name const &\
	) const;\
\
	bool \
	operator!=(\
		name const &\
	) const;

#endif
