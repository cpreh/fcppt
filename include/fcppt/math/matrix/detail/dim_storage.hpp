//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_DETAIL_DIM_STORAGE_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_DETAIL_DIM_STORAGE_HPP_INCLUDED

#include <fcppt/math/matrix/dim_type.hpp>
#include <fcppt/math/detail/dynamic_size.hpp>
#include <fcppt/math/dim/basic_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>

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
protected:
	typedef typename N::value_type size_type;

	typedef math::matrix::dim_type dim_type;

	explicit dim_storage();

	explicit dim_storage(
		dim_type const &
	);
public:
	size_type
	columns() const;

	size_type
	rows() const;
protected:
	void
	swap(
		dim_storage &
	);
};

template<>
class dim_storage<
	math::detail::dynamic_size,
	math::detail::dynamic_size
>
{
protected:
	typedef math::matrix::dim_type dim_type;

	typedef math::detail::dynamic_size::value_type size_type;

	explicit dim_storage(
		dim_type const &
	);

	dim_storage(
		dim_storage const &
	);

	dim_storage &
	operator=(
		dim_storage const &
	);

	~dim_storage();
public:
	size_type
	columns() const;

	size_type
	rows() const;
protected:
	void
	resize(
		dim_type const &
	);

	void
	swap(
		dim_storage &other_
	);
private:
	dim_type dim_;
};

}
}
}
}

#endif
