//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_DETAIL_DIM_STORAGE_IMPL_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_DETAIL_DIM_STORAGE_IMPL_HPP_INCLUDED

#include <fcppt/math/matrix/detail/dim_storage.hpp>
#include <fcppt/math/dim/basic_impl.hpp>

template<
	typename N,
	typename M
>
fcppt::math::matrix::detail::dim_storage<N, M>::dim_storage()
{}

template<
	typename N,
	typename M
>
fcppt::math::matrix::detail::dim_storage<N, M>::dim_storage(
	dim_type const &
)
{}

template<
	typename N,
	typename M
>
typename fcppt::math::matrix::detail::dim_storage<N, M>::size_type
fcppt::math::matrix::detail::dim_storage<N, M>::columns() const
{
	return N::value;
}

template<
	typename N,
	typename M
>
typename fcppt::math::matrix::detail::dim_storage<N, M>::size_type
fcppt::math::matrix::detail::dim_storage<N, M>::rows() const
{
	return M::value;
}

template<
	typename N,
	typename M
>
void
fcppt::math::matrix::detail::dim_storage<N, M>::swap(
	dim_storage &
)
{
}

inline
fcppt::math::matrix::detail::dim_storage<
	fcppt::math::detail::dynamic_size,
	fcppt::math::detail::dynamic_size
>::dim_storage(
	dim_type const &_dim
)
:
	dim_(_dim)
{}

inline
fcppt::math::matrix::detail::dim_storage<
	fcppt::math::detail::dynamic_size,
	fcppt::math::detail::dynamic_size
>::dim_storage(
	dim_storage const &_other
)
:
	dim_(_other.dim_)
{}

inline
fcppt::math::matrix::detail::dim_storage<
	fcppt::math::detail::dynamic_size,
	fcppt::math::detail::dynamic_size
> &
fcppt::math::matrix::detail::dim_storage<
	fcppt::math::detail::dynamic_size,
	fcppt::math::detail::dynamic_size
>::operator=(
	dim_storage const &_other
)
{
	// dim can already be self assigned
	dim_ = _other.dim_;

	return *this;
}

inline
fcppt::math::matrix::detail::dim_storage<
	fcppt::math::detail::dynamic_size,
	fcppt::math::detail::dynamic_size
>::~dim_storage()
{}

inline
void
fcppt::math::matrix::detail::dim_storage<
	fcppt::math::detail::dynamic_size,
	fcppt::math::detail::dynamic_size
>::resize(
	dim_type const &_dim
)
{
	dim_ = _dim;
}

inline
fcppt::math::matrix::detail::dim_storage<
	fcppt::math::detail::dynamic_size,
	fcppt::math::detail::dynamic_size
>::size_type
fcppt::math::matrix::detail::dim_storage<
	fcppt::math::detail::dynamic_size,
	fcppt::math::detail::dynamic_size
>::columns() const
{
	return dim_.w();
}

inline
fcppt::math::matrix::detail::dim_storage<
	fcppt::math::detail::dynamic_size,
	fcppt::math::detail::dynamic_size
>::size_type
fcppt::math::matrix::detail::dim_storage<
	fcppt::math::detail::dynamic_size,
	fcppt::math::detail::dynamic_size
>::rows() const
{
	return dim_.h();
}

inline
void
fcppt::math::matrix::detail::dim_storage<
	fcppt::math::detail::dynamic_size,
	fcppt::math::detail::dynamic_size
>::swap(
	dim_storage &_other
)
{
	dim_.swap(
		_other.dim_
	);
}

#endif
