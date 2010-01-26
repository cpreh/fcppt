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


#ifndef FCPPT_MATH_DETAIL_ARRAY_ADAPTER_IMPL_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_ARRAY_ADAPTER_IMPL_HPP_INCLUDED

#include <fcppt/math/detail/array_adapter.hpp>
#include <fcppt/math/compare.hpp>
#include <fcppt/assert.hpp>
#include <boost/next_prior.hpp>
#include <functional>
#include <algorithm>

template<
	typename Derived,
	typename ValueType,
	typename SizeType,
	typename Reference,
	typename ConstReference
>
Reference
fcppt::math::detail::array_adapter<
	Derived,
	ValueType,
	SizeType,
	Reference,
	ConstReference
>::at(
	size_type const index)
{
	FCPPT_ASSERT(index < this_().size());
	return this_()[index];
}

template<
	typename Derived,
	typename ValueType,
	typename SizeType,
	typename Reference,
	typename ConstReference
>
ConstReference
fcppt::math::detail::array_adapter<
	Derived,
	ValueType,
	SizeType,
	Reference,
	ConstReference
>::at(
	size_type const index) const
{
	FCPPT_ASSERT(index < this_().size());
	return this_()[index];
}

template<
	typename Derived,
	typename ValueType,
	typename SizeType,
	typename Reference,
	typename ConstReference
>
typename
fcppt::math::detail::array_adapter<
	Derived,
	ValueType,
	SizeType,
	Reference,
	ConstReference
>::pointer
fcppt::math::detail::array_adapter<
	Derived,
	ValueType,
	SizeType,
	Reference,
	ConstReference
>::data_end()
{
	return this_().data() + this_().size();
}

template<
	typename Derived,
	typename ValueType,
	typename SizeType,
	typename Reference,
	typename ConstReference
>
typename
fcppt::math::detail::array_adapter<
	Derived,
	ValueType,
	SizeType,
	Reference,
	ConstReference
>::const_pointer
fcppt::math::detail::array_adapter<
	Derived,
	ValueType,
	SizeType,
	Reference,
	ConstReference
>::data_end() const
{
	return this_().data() + this_().size();
}

template<
	typename Derived,
	typename ValueType,
	typename SizeType,
	typename Reference,
	typename ConstReference
>
typename
fcppt::math::detail::array_adapter<
	Derived,
	ValueType,
	SizeType,
	Reference,
	ConstReference
>::iterator
fcppt::math::detail::array_adapter<
	Derived
	,ValueType,
	SizeType,
	Reference,
	ConstReference
>::begin()
{
	return iterator(
		this_().data());
}

template<
	typename Derived,
	typename ValueType,
	typename SizeType,
	typename Reference,
	typename ConstReference
>
typename
fcppt::math::detail::array_adapter<
	Derived,
	ValueType,
	SizeType,
	Reference,
	ConstReference
>::const_iterator
fcppt::math::detail::array_adapter<
	Derived,
	ValueType,
	SizeType,
	Reference,
	ConstReference
>::begin() const
{
	return const_iterator(
		this_().data());
}

template<
	typename Derived,
	typename ValueType,
	typename SizeType,
	typename Reference,
	typename ConstReference
>
typename
fcppt::math::detail::array_adapter<
	Derived,
	ValueType,
	SizeType,
	Reference,
	ConstReference
>::iterator
fcppt::math::detail::array_adapter<
	Derived,
	ValueType,
	SizeType,
	Reference,
	ConstReference
>::end()
{
	return iterator(
		data_end());
}

template<
	typename Derived,
	typename ValueType,
	typename SizeType,
	typename Reference,
	typename ConstReference
>
typename
fcppt::math::detail::array_adapter<
	Derived,
	ValueType,
	SizeType,
	Reference,
	ConstReference
>::const_iterator
fcppt::math::detail::array_adapter<
	Derived,
	ValueType,
	SizeType,
	Reference,
	ConstReference
>::end() const
{
	return const_iterator(
		data_end());
}

template<
	typename Derived,
	typename ValueType,
	typename SizeType,
	typename Reference,
	typename ConstReference
>
typename
fcppt::math::detail::array_adapter<
	Derived,
	ValueType,
	SizeType,
	Reference,
	ConstReference
>::reverse_iterator
fcppt::math::detail::array_adapter<
	Derived,
	ValueType,
	SizeType,
	Reference,
	ConstReference
>::rbegin()
{
	return reverse_iterator(
		end());
}

template<
	typename Derived,
	typename ValueType,
	typename SizeType,
	typename Reference,
	typename ConstReference
>
typename
fcppt::math::detail::array_adapter<
	Derived,
	ValueType,
	SizeType,
	Reference,
	ConstReference
>::const_reverse_iterator
fcppt::math::detail::array_adapter<
	Derived,
	ValueType,
	SizeType,
	Reference,
	ConstReference
>::rbegin() const
{
	return const_reverse_iterator(
		end());
}

template<
	typename Derived,
	typename ValueType,
	typename SizeType,
	typename Reference,
	typename ConstReference
>
typename
fcppt::math::detail::array_adapter<
	Derived,
	ValueType,
	SizeType,
	Reference,
	ConstReference
>::reverse_iterator
fcppt::math::detail::array_adapter<
	Derived,
	ValueType,
	SizeType,
	Reference,
	ConstReference
>::rend()
{
	return reverse_iterator(
		begin());
}

template<
	typename Derived,
	typename ValueType,
	typename SizeType,
	typename Reference,
	typename ConstReference
>
typename
fcppt::math::detail::array_adapter<
	Derived,
	ValueType,
	SizeType,
	Reference,
	ConstReference
>::const_reverse_iterator
fcppt::math::detail::array_adapter<
	Derived,
	ValueType,
	SizeType,
	Reference,
	ConstReference
>::rend() const
{
	return const_reverse_iterator(
		begin());
}

template<
	typename Derived,
	typename ValueType,
	typename SizeType,
	typename Reference,
	typename ConstReference
>

typename
fcppt::math::detail::array_adapter<
	Derived,
	ValueType,
	SizeType,
	Reference,
	ConstReference
>::value_type &
fcppt::math::detail::array_adapter<
	Derived,
	ValueType,
	SizeType,
	Reference,
	ConstReference
>::back()
{
	return *boost::prior(end());
}

template<
	typename Derived,
	typename ValueType,
	typename SizeType,
	typename Reference,
	typename ConstReference
>
typename
fcppt::math::detail::array_adapter<
	Derived,
	ValueType,
	SizeType,
	Reference,
	ConstReference
>::value_type const &
fcppt::math::detail::array_adapter<
	Derived,
	ValueType,
	SizeType,
	Reference,
	ConstReference
>::back() const
{
	return *boost::prior(end());
}

template<
	typename Derived,
	typename ValueType,
	typename SizeType,
	typename Reference,
	typename ConstReference
>
typename
fcppt::math::detail::array_adapter<
	Derived,
	ValueType,
	SizeType,
	Reference,
	ConstReference
>::value_type &
fcppt::math::detail::array_adapter<
	Derived,
	ValueType,
	SizeType,
	Reference,
	ConstReference
>::front()
{
	return *begin();
}

template<
	typename Derived,
	typename ValueType,
	typename SizeType,
	typename Reference,
	typename ConstReference
>
typename
fcppt::math::detail::array_adapter<
	Derived,
	ValueType,
	SizeType,
	Reference,
	ConstReference
>::value_type const &
fcppt::math::detail::array_adapter<
	Derived,
	ValueType,
	SizeType,
	Reference,
	ConstReference
>::front() const
{
	return *begin();
}

template<
	typename Derived,
	typename ValueType,
	typename SizeType,
	typename Reference,
	typename ConstReference
>
bool
fcppt::math::detail::array_adapter<
	Derived,
	ValueType,
	SizeType,
	Reference,
	ConstReference
>::empty() const
{
	return !this_().size();
}

template<
	typename Derived,
	typename ValueType,
	typename SizeType,
	typename Reference,
	typename ConstReference
>
bool
fcppt::math::detail::array_adapter<
	Derived,
	ValueType,
	SizeType,
	Reference,
	ConstReference
>::operator==(
	Derived const &r) const
{
	return this_().size() == r.size()
		&& std::equal(
			begin(),
			end(),
			r.begin(),
			std::ptr_fun(
				compare<
					ValueType
				>));
}

template<
	typename Derived,
	typename ValueType,
	typename SizeType,
	typename Reference,
	typename ConstReference
>
bool
fcppt::math::detail::array_adapter<
	Derived,
	ValueType,
	SizeType,
	Reference,
	ConstReference
>::operator!=(
	Derived const &r) const
{
	return !(*this == r);
}

template<
	typename Derived,
	typename ValueType,
	typename SizeType,
	typename Reference,
	typename ConstReference
>
Derived &
fcppt::math::detail::array_adapter<
	Derived,
	ValueType,
	SizeType,
	Reference,
	ConstReference
>::this_()
{
	return static_cast<Derived &>(*this);
}

template<
	typename Derived,
	typename ValueType,
	typename SizeType,
	typename Reference,
	typename ConstReference
>
Derived const &
fcppt::math::detail::array_adapter<
	Derived,
	ValueType,
	SizeType,
	Reference,
	ConstReference
>::this_() const
{
	return static_cast<Derived const &>(*this);
}

#define FCPPT_MATH_DETAIL_ARRAY_ADAPTER_IMPL\
\
FCPPT_MATH_DETAIL_TEMPLATE_PRE\
typename FCPPT_MATH_DETAIL_CLASS_PRE ::reference \
FCPPT_MATH_DETAIL_CLASS_PRE ::at(\
	size_type const sz_\
)\
{\
	FCPPT_ASSERT(index < size());\
	return (*this)[index];\
}\
\
FCPPT_MATH_DETAIL_TEMPLATE_PRE\
typename FCPPT_MATH_DETAIL_CLASS_PRE ::reference \
FCPPT_MATH_DETAIL_CLASS_PRE ::at(\
	size_type const sz_\
) const\
{\
	FCPPT_ASSERT(index < size());\
	return (*this)[index];\
}\
\
FCPPT_MATH_DETAIL_TEMPLATE_PRE\
typename FCPPT_MATH_DETAIL_CLASS_PRE ::pointer \
FCPPT_MATH_DETAIL_CLASS_PRE ::data_end() \
{\
	return data() + size();\
}\
\
FCPPT_MATH_DETAIL_TEMPLATE_PRE\
typename FCPPT_MATH_DETAIL_CLASS_PRE ::const_pointer \
FCPPT_MATH_DETAIL_CLASS_PRE ::data_end() const\
{\
	return data() + size();\
}\
\
FCPPT_MATH_DETAIL_TEMPLATE_PRE\
typename FCPPT_MATH_DETAIL_CLASS_PRE ::iterator \
FCPPT_MATH_DETAIL_CLASS_PRE ::begin() \
{\
	return iterator(data());\
}\
\
FCPPT_MATH_DETAIL_TEMPLATE_PRE\
typename FCPPT_MATH_DETAIL_CLASS_PRE ::const_iterator \
FCPPT_MATH_DETAIL_CLASS_PRE ::begin() const\
{\
	return const_iterator(data());\
}\
\
FCPPT_MATH_DETAIL_TEMPLATE_PRE\
typename FCPPT_MATH_DETAIL_CLASS_PRE ::iterator \
FCPPT_MATH_DETAIL_CLASS_PRE ::end()\
{\
	return iterator(data_end());\
}\
\
FCPPT_MATH_DETAIL_TEMPLATE_PRE\
typename FCPPT_MATH_DETAIL_CLASS_PRE ::const_iterator \
FCPPT_MATH_DETAIL_CLASS_PRE ::end() const\
{\
	return const_iterator(data_end());\
}\
\
FCPPT_MATH_DETAIL_TEMPLATE_PRE\
typename FCPPT_MATH_DETAIL_CLASS_PRE ::iterator \
FCPPT_MATH_DETAIL_CLASS_PRE ::rbegin() \
{\
	return reverse_iterator(end());\
}\
\
FCPPT_MATH_DETAIL_TEMPLATE_PRE\
typename FCPPT_MATH_DETAIL_CLASS_PRE ::const_iterator \
FCPPT_MATH_DETAIL_CLASS_PRE ::rbegin() const\
{\
	return const_reverse_iterator(end());\
}\
\
FCPPT_MATH_DETAIL_TEMPLATE_PRE\
typename FCPPT_MATH_DETAIL_CLASS_PRE ::iterator \
FCPPT_MATH_DETAIL_CLASS_PRE ::rend() \
{\
	return reverse_iterator(begin());\
}\
\
FCPPT_MATH_DETAIL_TEMPLATE_PRE\
typename FCPPT_MATH_DETAIL_CLASS_PRE ::const_iterator \
FCPPT_MATH_DETAIL_CLASS_PRE ::rend() const\
{\
	return const_reverse_iterator(begin());\
}\
\
FCPPT_MATH_DETAIL_TEMPLATE_PRE\
typename FCPPT_MATH_DETAIL_CLASS_PRE ::reference \
FCPPT_MATH_DETAIL_CLASS_PRE ::back()\
{\
	return *boost::prior(end());\
}\
\
FCPPT_MATH_DETAIL_TEMPLATE_PRE\
typename FCPPT_MATH_DETAIL_CLASS_PRE ::const_reference \
FCPPT_MATH_DETAIL_CLASS_PRE ::back() const\
{\
	return *boost::prior(end());\
}\
\
FCPPT_MATH_DETAIL_TEMPLATE_PRE\
typename FCPPT_MATH_DETAIL_CLASS_PRE ::reference \
FCPPT_MATH_DETAIL_CLASS_PRE ::front()\
{\
	return *begin();\
}\
\
FCPPT_MATH_DETAIL_TEMPLATE_PRE\
typename FCPPT_MATH_DETAIL_CLASS_PRE ::const_reference \
FCPPT_MATH_DETAIL_CLASS_PRE ::front() const\
{\
	return *begin();\
}\
\
FCPPT_MATH_DETAIL_TEMPLATE_PRE\
bool \
FCPPT_MATH_DETAIL_CLASS_PRE ::empty() const\
{\
	return size() == 0u;\
}\
\
FCPPT_MATH_DETAIL_TEMPLATE_PRE\
bool \
FCPPT_MATH_DETAIL_CLASS_PRE ::operator==(\
	FCPPT_MATH_DETAIL_CLASS_PRE const &other_\
) const\
{\
	return \
		size() == other_.size() \
		&& std::equal(\
			begin(),\
			end(),\
			r.begin(),\
			std::tr1::bind(\
				compare<\
					value_type\
				>,\
				std::tr1::placeholders::_1,\
				std::tr1::placeholders::_2\
			)\
		);\
}\
\
FCPPT_MATH_DETAIL_TEMPLATE_PRE\
bool \
FCPPT_MATH_DETAIL_CLASS_PRE ::operator!=(\
	FCPPT_MATH_DETAIL_CLASS_PRE const &other_\
) const\
{\
	return !(*this == other_);\
}

#endif
