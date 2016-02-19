//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_MAKE_OP_DEF_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_MAKE_OP_DEF_HPP_INCLUDED

#include <fcppt/tag_value.hpp>
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
			auto const index(\
				fcppt::tag_value(\
					_index\
				)\
			);\
			\
			fcppt::math::detail::linear_access<\
				index\
			>(\
				storage_\
			) \
			op \
			fcppt::math::detail::linear_access<\
				index\
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
