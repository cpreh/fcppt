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

#include <iterator>

namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename Derived,
	typename ValueType,
	typename SizeType,
	typename Reference = ValueType &,
	typename ConstReference = ValueType const &
>
class array_adapter {
public:
	typedef SizeType size_type;
	typedef ValueType value_type;
	typedef Reference reference;
	typedef ConstReference const_reference;
	typedef value_type *pointer;
	typedef value_type const *const_pointer;
	typedef pointer iterator;
	typedef const_pointer const_iterator;
	typedef std::reverse_iterator<iterator> reverse_iterator;
	typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

	reference at(
		size_type);
	const_reference at(
		size_type) const;

	pointer data_end();
	const_pointer data_end() const;

	iterator begin();
	const_iterator begin() const;
	iterator end();
	const_iterator end() const;
	reverse_iterator rbegin();
	const_reverse_iterator rbegin() const;
	reverse_iterator rend();
	const_reverse_iterator rend() const;

	value_type &back();
	value_type const &back() const;
	value_type &front();
	value_type const &front() const;

	bool empty() const;

	bool operator==(
		Derived const &) const;
	bool operator!=(
		Derived const &) const;
private:
	Derived &this_();
	Derived const &this_() const;
};

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
	value_type &\
	back();\
\
	value_type const &\
	back() const;\
\
	value_type &\
	front();\
\
	value_type const &\
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

}
}
}

#endif
