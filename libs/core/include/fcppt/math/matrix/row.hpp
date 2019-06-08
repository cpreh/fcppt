//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_ROW_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_ROW_HPP_INCLUDED

#include <fcppt/brigand/all_of.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/matrix/row_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/sequences/list.hpp>
#include <brigand/types/args.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{

/**
\brief Creates a matrix row for initialization

\ingroup fcpptmathmatrix
*/
template<
	typename Type,
	typename ...Args
>
inline
auto
row(
	Type const &_value,
	Args const & ..._args
)
{
	static_assert(
		fcppt::brigand::all_of<
			::brigand::list<
				Args...
			>,
			std::is_same<
				::brigand::_1,
				Type
			>
		>::value,
		"All row elements must have the same type"
	);

	return
		fcppt::math::matrix::row_type<
			Type,
			fcppt::cast::size<
				fcppt::math::size_type
			>(
				sizeof...(
					Args
				)
				+
				1u
			)
		>{
			_value,
			_args...
		};
}

}
}
}

#endif
