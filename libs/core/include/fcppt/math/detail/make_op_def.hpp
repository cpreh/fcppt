//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_MAKE_OP_DEF_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_MAKE_OP_DEF_HPP_INCLUDED

#include <fcppt/tag_type.hpp>
#include <fcppt/use.hpp>
#include <fcppt/algorithm/loop.hpp>
#include <fcppt/math/int_range_count.hpp>
#include <fcppt/math/detail/linear_access.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/preprocessor/tuple/rem.hpp>
#include <fcppt/config/external_end.hpp>


#define FCPPT_MATH_DETAIL_MAKE_OP_DEF(\
	class_arity,\
	template_pre,\
	def_pre,\
	arg,\
	op\
)\
BOOST_PP_TUPLE_REM(class_arity)template_pre \
inline \
BOOST_PP_TUPLE_REM(class_arity)def_pre \
& \
BOOST_PP_TUPLE_REM(class_arity)def_pre \
::operator op( \
	BOOST_PP_TUPLE_REM(class_arity)arg const &expr\
) \
{\
	fcppt::algorithm::loop(\
		fcppt::math::int_range_count<\
			dim_wrapper::value \
		>{},\
		[\
			this,\
			&expr\
		](\
			auto const _index\
		){ \
			FCPPT_USE(\
				_index\
			);\
			\
			typedef \
			fcppt::tag_type<\
				decltype(\
					_index\
				)\
			>\
			index;\
			\
			fcppt::math::detail::linear_access<\
				index::value\
			>(\
				storage_\
			) \
			op \
			fcppt::math::detail::linear_access<\
				index::value\
			>(\
				expr.storage()\
			);\
		}\
	);\
	\
	return \
		*this;\
}

#endif
