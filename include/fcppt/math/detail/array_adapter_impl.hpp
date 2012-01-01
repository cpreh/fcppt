//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_ARRAY_ADAPTER_IMPL_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_ARRAY_ADAPTER_IMPL_HPP_INCLUDED

#include <fcppt/assert/exception.hpp>
#include <fcppt/assert/throw.hpp>
#include <fcppt/math/detail/array_adapter.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/next_prior.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>


#define FCPPT_MATH_DETAIL_ARRAY_ADAPTER_IMPL(\
	class_arity,\
	template_pre,\
	def_pre\
)\
BOOST_PP_TUPLE_REM(class_arity)template_pre \
typename BOOST_PP_TUPLE_REM(class_arity)def_pre ::reference \
BOOST_PP_TUPLE_REM(class_arity)def_pre ::at(\
	size_type const index\
)\
{\
	FCPPT_ASSERT_THROW(\
		index < size(),\
		fcppt::assert_::exception\
	); \
\
	return (*this)[index];\
}\
\
BOOST_PP_TUPLE_REM(class_arity)template_pre \
typename BOOST_PP_TUPLE_REM(class_arity)def_pre ::const_reference \
BOOST_PP_TUPLE_REM(class_arity)def_pre ::at(\
	size_type const index\
) const\
{\
	FCPPT_ASSERT_THROW(\
		index < size(),\
		fcppt::assert_::exception\
	); \
\
	return (*this)[index];\
}\
\
BOOST_PP_TUPLE_REM(class_arity)template_pre \
typename BOOST_PP_TUPLE_REM(class_arity)def_pre ::pointer \
BOOST_PP_TUPLE_REM(class_arity)def_pre ::data_end() \
{\
	return data() + size();\
}\
\
BOOST_PP_TUPLE_REM(class_arity)template_pre \
typename BOOST_PP_TUPLE_REM(class_arity)def_pre ::const_pointer \
BOOST_PP_TUPLE_REM(class_arity)def_pre ::data_end() const\
{\
	return data() + size();\
}\
\
BOOST_PP_TUPLE_REM(class_arity)template_pre \
typename BOOST_PP_TUPLE_REM(class_arity)def_pre ::iterator \
BOOST_PP_TUPLE_REM(class_arity)def_pre ::begin() \
{\
	return static_cast<iterator>(data());\
}\
\
BOOST_PP_TUPLE_REM(class_arity)template_pre \
typename BOOST_PP_TUPLE_REM(class_arity)def_pre ::const_iterator \
BOOST_PP_TUPLE_REM(class_arity)def_pre ::begin() const\
{\
	return static_cast<const_iterator>(data());\
}\
\
BOOST_PP_TUPLE_REM(class_arity)template_pre \
typename BOOST_PP_TUPLE_REM(class_arity)def_pre ::iterator \
BOOST_PP_TUPLE_REM(class_arity)def_pre ::end()\
{\
	return static_cast<iterator>(data_end());\
}\
\
BOOST_PP_TUPLE_REM(class_arity)template_pre \
typename BOOST_PP_TUPLE_REM(class_arity)def_pre ::const_iterator \
BOOST_PP_TUPLE_REM(class_arity)def_pre ::end() const\
{\
	return static_cast<const_iterator>(data_end());\
}\
\
BOOST_PP_TUPLE_REM(class_arity)template_pre \
typename BOOST_PP_TUPLE_REM(class_arity)def_pre ::reverse_iterator \
BOOST_PP_TUPLE_REM(class_arity)def_pre ::rbegin() \
{\
	return reverse_iterator(end());\
}\
\
BOOST_PP_TUPLE_REM(class_arity)template_pre \
typename BOOST_PP_TUPLE_REM(class_arity)def_pre ::const_reverse_iterator \
BOOST_PP_TUPLE_REM(class_arity)def_pre ::rbegin() const\
{\
	return const_reverse_iterator(end());\
}\
\
BOOST_PP_TUPLE_REM(class_arity)template_pre \
typename BOOST_PP_TUPLE_REM(class_arity)def_pre ::reverse_iterator \
BOOST_PP_TUPLE_REM(class_arity)def_pre ::rend() \
{\
	return reverse_iterator(begin());\
}\
\
BOOST_PP_TUPLE_REM(class_arity)template_pre \
typename BOOST_PP_TUPLE_REM(class_arity)def_pre ::const_reverse_iterator \
BOOST_PP_TUPLE_REM(class_arity)def_pre ::rend() const\
{\
	return const_reverse_iterator(begin());\
}\
\
BOOST_PP_TUPLE_REM(class_arity)template_pre \
typename BOOST_PP_TUPLE_REM(class_arity)def_pre ::reference \
BOOST_PP_TUPLE_REM(class_arity)def_pre ::back()\
{\
	return *boost::prior(end());\
}\
\
BOOST_PP_TUPLE_REM(class_arity)template_pre \
typename BOOST_PP_TUPLE_REM(class_arity)def_pre ::const_reference \
BOOST_PP_TUPLE_REM(class_arity)def_pre ::back() const\
{\
	return *boost::prior(end());\
}\
\
BOOST_PP_TUPLE_REM(class_arity)template_pre \
typename BOOST_PP_TUPLE_REM(class_arity)def_pre ::reference \
BOOST_PP_TUPLE_REM(class_arity)def_pre ::front()\
{\
	return *begin();\
}\
\
BOOST_PP_TUPLE_REM(class_arity)template_pre \
typename BOOST_PP_TUPLE_REM(class_arity)def_pre ::const_reference \
BOOST_PP_TUPLE_REM(class_arity)def_pre ::front() const\
{\
	return *begin();\
}\
\
BOOST_PP_TUPLE_REM(class_arity)template_pre \
bool \
BOOST_PP_TUPLE_REM(class_arity)def_pre ::empty() const\
{\
	return begin() == end();\
}

#endif
