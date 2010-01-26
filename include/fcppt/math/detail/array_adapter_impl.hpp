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
#include <fcppt/tr1/functional.hpp>
#include <fcppt/math/compare.hpp>
#include <fcppt/assert.hpp>
#include <boost/next_prior.hpp>
#include <algorithm>

#define FCPPT_MATH_DETAIL_ARRAY_ADAPTER_IMPL \
FCPPT_MATH_DETAIL_TEMPLATE_PRE \
typename FCPPT_MATH_DETAIL_DEF_PRE ::reference \
FCPPT_MATH_DETAIL_DEF_PRE ::at(\
	size_type const index\
)\
{\
	FCPPT_ASSERT(index < size());\
	return (*this)[index];\
}\
\
FCPPT_MATH_DETAIL_TEMPLATE_PRE \
typename FCPPT_MATH_DETAIL_DEF_PRE ::const_reference \
FCPPT_MATH_DETAIL_DEF_PRE ::at(\
	size_type const index\
) const\
{\
	FCPPT_ASSERT(index < size());\
	return (*this)[index];\
}\
\
FCPPT_MATH_DETAIL_TEMPLATE_PRE \
typename FCPPT_MATH_DETAIL_DEF_PRE ::pointer \
FCPPT_MATH_DETAIL_DEF_PRE ::data_end() \
{\
	return data() + size();\
}\
\
FCPPT_MATH_DETAIL_TEMPLATE_PRE \
typename FCPPT_MATH_DETAIL_DEF_PRE ::const_pointer \
FCPPT_MATH_DETAIL_DEF_PRE ::data_end() const\
{\
	return data() + size();\
}\
\
FCPPT_MATH_DETAIL_TEMPLATE_PRE \
typename FCPPT_MATH_DETAIL_DEF_PRE ::iterator \
FCPPT_MATH_DETAIL_DEF_PRE ::begin() \
{\
	return iterator(data());\
}\
\
FCPPT_MATH_DETAIL_TEMPLATE_PRE \
typename FCPPT_MATH_DETAIL_DEF_PRE ::const_iterator \
FCPPT_MATH_DETAIL_DEF_PRE ::begin() const\
{\
	return const_iterator(data());\
}\
\
FCPPT_MATH_DETAIL_TEMPLATE_PRE \
typename FCPPT_MATH_DETAIL_DEF_PRE ::iterator \
FCPPT_MATH_DETAIL_DEF_PRE ::end()\
{\
	return iterator(data_end());\
}\
\
FCPPT_MATH_DETAIL_TEMPLATE_PRE \
typename FCPPT_MATH_DETAIL_DEF_PRE ::const_iterator \
FCPPT_MATH_DETAIL_DEF_PRE ::end() const\
{\
	return const_iterator(data_end());\
}\
\
FCPPT_MATH_DETAIL_TEMPLATE_PRE \
typename FCPPT_MATH_DETAIL_DEF_PRE ::reverse_iterator \
FCPPT_MATH_DETAIL_DEF_PRE ::rbegin() \
{\
	return reverse_iterator(end());\
}\
\
FCPPT_MATH_DETAIL_TEMPLATE_PRE \
typename FCPPT_MATH_DETAIL_DEF_PRE ::const_reverse_iterator \
FCPPT_MATH_DETAIL_DEF_PRE ::rbegin() const\
{\
	return const_reverse_iterator(end());\
}\
\
FCPPT_MATH_DETAIL_TEMPLATE_PRE \
typename FCPPT_MATH_DETAIL_DEF_PRE ::reverse_iterator \
FCPPT_MATH_DETAIL_DEF_PRE ::rend() \
{\
	return reverse_iterator(begin());\
}\
\
FCPPT_MATH_DETAIL_TEMPLATE_PRE \
typename FCPPT_MATH_DETAIL_DEF_PRE ::const_reverse_iterator \
FCPPT_MATH_DETAIL_DEF_PRE ::rend() const\
{\
	return const_reverse_iterator(begin());\
}\
\
FCPPT_MATH_DETAIL_TEMPLATE_PRE \
typename FCPPT_MATH_DETAIL_DEF_PRE ::reference \
FCPPT_MATH_DETAIL_DEF_PRE ::back()\
{\
	return *boost::prior(end());\
}\
\
FCPPT_MATH_DETAIL_TEMPLATE_PRE \
typename FCPPT_MATH_DETAIL_DEF_PRE ::const_reference \
FCPPT_MATH_DETAIL_DEF_PRE ::back() const\
{\
	return *boost::prior(end());\
}\
\
FCPPT_MATH_DETAIL_TEMPLATE_PRE \
typename FCPPT_MATH_DETAIL_DEF_PRE ::reference \
FCPPT_MATH_DETAIL_DEF_PRE ::front()\
{\
	return *begin();\
}\
\
FCPPT_MATH_DETAIL_TEMPLATE_PRE \
typename FCPPT_MATH_DETAIL_DEF_PRE ::const_reference \
FCPPT_MATH_DETAIL_DEF_PRE ::front() const\
{\
	return *begin();\
}\
\
FCPPT_MATH_DETAIL_TEMPLATE_PRE \
bool \
FCPPT_MATH_DETAIL_DEF_PRE ::empty() const\
{\
	return size() == 0u;\
}\
\
FCPPT_MATH_DETAIL_TEMPLATE_PRE \
bool \
FCPPT_MATH_DETAIL_DEF_PRE ::operator==(\
	FCPPT_MATH_DETAIL_DEF_PRE const &other_\
) const\
{\
	return \
		size() == other_.size() \
		&& std::equal(\
			begin(),\
			end(),\
			other_.begin(),\
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
FCPPT_MATH_DETAIL_TEMPLATE_PRE \
bool \
FCPPT_MATH_DETAIL_DEF_PRE ::operator!=(\
	FCPPT_MATH_DETAIL_DEF_PRE const &other_\
) const\
{\
	return !(*this == other_);\
}

#endif
