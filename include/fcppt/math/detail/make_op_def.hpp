//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_MAKE_OP_DEF_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_MAKE_OP_DEF_HPP_INCLUDED

#include <fcppt/math/detail/storage_dim.hpp>

#define FCPPT_MATH_DETAIL_MAKE_OP_DEF(name, op)\
FCPPT_MATH_DETAIL_TEMPLATE_PRE \
template< \
	typename Expr \
> \
FCPPT_MATH_DETAIL_DEF_PRE \
 & \
FCPPT_MATH_DETAIL_DEF_PRE \
::operator op ( \
	Expr const &expr) \
{ \
	size_type const dim(\
		static_cast<\
			size_type\
		>( \
			::fcppt::math::detail::storage_dim(\
				storage)));\
	for( \
		size_type i = 0; \
		i < dim; \
		++i \
	) \
		(*this)[i] op expr[i]; \
	return *this; \
}

#endif
