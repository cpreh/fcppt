//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_INDEX_DECL_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_INDEX_DECL_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/matrix/index_fwd.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{

template<
	fcppt::math::size_type Row,
	fcppt::math::size_type Column
>
struct index
{
	static
	constexpr
	fcppt::math::size_type
	row();

	static
	constexpr
	fcppt::math::size_type
	column();
};

}
}
}

#endif
