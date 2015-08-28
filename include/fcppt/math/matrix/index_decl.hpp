//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_INDEX_DECL_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_INDEX_DECL_HPP_INCLUDED

#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/strong_typedef_impl.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/matrix/index_fwd.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{

class index
{
public:
	FCPPT_MAKE_STRONG_TYPEDEF(
		fcppt::math::size_type,
		row_t
	);

	FCPPT_MAKE_STRONG_TYPEDEF(
		fcppt::math::size_type,
		column_t
	);

	index(
		row_t,
		column_t
	);

	fcppt::math::size_type
	row() const;

	fcppt::math::size_type
	column() const;
private:
	row_t row_;

	column_t column_;
};

}
}
}

#endif
