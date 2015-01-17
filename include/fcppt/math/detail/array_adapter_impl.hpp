//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_ARRAY_ADAPTER_IMPL_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_ARRAY_ADAPTER_IMPL_HPP_INCLUDED

#include <fcppt/assert/exception.hpp>
#include <fcppt/assert/throw.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/cast/to_signed.hpp>
#include <fcppt/math/detail/array_adapter.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <iterator>
#include <fcppt/config/external_end.hpp>


#define FCPPT_MATH_DETAIL_ARRAY_ADAPTER_IMPL(\
	class_arity,\
	template_pre,\
	def_pre\
)\
BOOST_PP_TUPLE_REM(class_arity)template_pre \
typename BOOST_PP_TUPLE_REM(class_arity)def_pre ::pointer \
BOOST_PP_TUPLE_REM(class_arity)def_pre ::data()\
{\
	return storage_.data();\
}\
\
BOOST_PP_TUPLE_REM(class_arity)template_pre \
typename BOOST_PP_TUPLE_REM(class_arity)def_pre ::const_pointer \
BOOST_PP_TUPLE_REM(class_arity)def_pre ::data() const\
{\
	return storage_.data();\
}\
\
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
typename BOOST_PP_TUPLE_REM(class_arity)def_pre ::iterator \
BOOST_PP_TUPLE_REM(class_arity)def_pre ::begin() \
{\
	return storage_.begin();\
}\
\
BOOST_PP_TUPLE_REM(class_arity)template_pre \
typename BOOST_PP_TUPLE_REM(class_arity)def_pre ::const_iterator \
BOOST_PP_TUPLE_REM(class_arity)def_pre ::begin() const\
{\
	return storage_.begin();\
}\
\
BOOST_PP_TUPLE_REM(class_arity)template_pre \
typename BOOST_PP_TUPLE_REM(class_arity)def_pre ::iterator \
BOOST_PP_TUPLE_REM(class_arity)def_pre ::end()\
{\
	return \
		this->begin() \
		+ \
		fcppt::cast::to_signed(\
			this->size()\
		);\
}\
\
BOOST_PP_TUPLE_REM(class_arity)template_pre \
typename BOOST_PP_TUPLE_REM(class_arity)def_pre ::const_iterator \
BOOST_PP_TUPLE_REM(class_arity)def_pre ::end() const\
{\
	return \
		this->begin() \
		+ \
		fcppt::cast::to_signed(\
			this->size()\
		);\
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
	return *std::prev(end());\
}\
\
BOOST_PP_TUPLE_REM(class_arity)template_pre \
typename BOOST_PP_TUPLE_REM(class_arity)def_pre ::const_reference \
BOOST_PP_TUPLE_REM(class_arity)def_pre ::back() const\
{\
	return *std::prev(end());\
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
	return this->begin() == this->end();\
}\
\
BOOST_PP_TUPLE_REM(class_arity)template_pre \
typename BOOST_PP_TUPLE_REM(class_arity)def_pre ::size_type \
BOOST_PP_TUPLE_REM(class_arity)def_pre ::size() const\
{\
	return \
		fcppt::cast::size<\
			size_type\
		>(\
			storage_.size()\
		);\
}

#endif
