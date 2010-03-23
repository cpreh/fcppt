//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_DETAIL_DIM_STORAGE_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_DETAIL_DIM_STORAGE_HPP_INCLUDED

#include <fcppt/math/detail/dynamic_size.hpp>
#include <algorithm>

namespace fcppt
{
namespace math
{
namespace matrix
{
namespace detail
{

template<
	typename N,
	typename M
>
class dim_storage
{
public:
	typedef typename N::value_type size_type;

	size_type
	columns() const
	{
		return N::value;
	}

	size_type
	rows() const
	{
		return M::value;
	}

	void
	swap_base(
		dim_storage &
	)
	{
	}
};

template<>
class dim_storage<
	math::detail::dynamic_size,
	math::detail::dynamic_size
>
{
public:
	typedef math::detail::dynamic_size::value_type size_type;

	size_type
	columns() const
	{
		return columns_;
	}

	size_type
	rows() const
	{
		return rows_;
	}

	void
	columns(
		size_type const ncolumns
	)
	{
		columns_ = ncolumns;
	}

	void
	rows(
		size_type const nrows
	)
	{
		rows_ = nrows;
	}

	void
	swap_base(
		dim_storage &other_
	)
	{
		std::swap(
			columns_,
			other_.columns_
		);


		std::swap(
			rows_,
			other_.rows_
		);
	}
private:
	size_type
		columns_,
		rows_;
};

}
}
}
}

#endif
