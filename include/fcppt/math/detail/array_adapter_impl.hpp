//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_ARRAY_ADAPTER_IMPL_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_ARRAY_ADAPTER_IMPL_HPP_INCLUDED

#include <fcppt/math/detail/array_adapter.hpp>
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
	return static_cast<iterator>(data());\
}\
\
FCPPT_MATH_DETAIL_TEMPLATE_PRE \
typename FCPPT_MATH_DETAIL_DEF_PRE ::const_iterator \
FCPPT_MATH_DETAIL_DEF_PRE ::begin() const\
{\
	return static_cast<const_iterator>(data());\
}\
\
FCPPT_MATH_DETAIL_TEMPLATE_PRE \
typename FCPPT_MATH_DETAIL_DEF_PRE ::iterator \
FCPPT_MATH_DETAIL_DEF_PRE ::end()\
{\
	return static_cast<iterator>(data_end());\
}\
\
FCPPT_MATH_DETAIL_TEMPLATE_PRE \
typename FCPPT_MATH_DETAIL_DEF_PRE ::const_iterator \
FCPPT_MATH_DETAIL_DEF_PRE ::end() const\
{\
	return static_cast<const_iterator>(data_end());\
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

#endif
