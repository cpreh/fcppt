//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_BASIC_IMPL_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_BASIC_IMPL_HPP_INCLUDED

#include <fcppt/math/matrix/detail/dim_storage_impl.hpp>
#include <fcppt/math/matrix/detail/row_view_impl.hpp>
#include <fcppt/math/matrix/basic_decl.hpp>
#include <fcppt/math/compare.hpp>
#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/dim/basic_impl.hpp>
#include <fcppt/math/detail/array_adapter_impl.hpp>
#include <fcppt/math/detail/storage_data.hpp>
#include <fcppt/math/detail/storage_dim.hpp>
#include <fcppt/math/detail/make_variadic_constructor.hpp>
#include <fcppt/math/detail/initial_size.hpp>
#include <fcppt/math/detail/make_op_def.hpp>
#include <fcppt/math/detail/assign.hpp>
#include <fcppt/assert.hpp>
#include <boost/foreach.hpp>
#include <iterator>
#include <algorithm>

template<
	typename T,
	typename N,
	typename M,
	typename S
>
fcppt::math::matrix::basic<T, N, M, S>::basic()
:
	dim_base()
{}

template<
	typename T,
	typename N,
	typename M,
	typename S
>
fcppt::math::matrix::basic<T, N, M, S>::basic(
	dim const &_dim
)
:
	dim_base(
		_dim
	)
{}

template<
	typename T,
	typename N,
	typename M,
	typename S
>
fcppt::math::matrix::basic<T, N, M, S>::basic(
	storage_type const &_storage
)
:
	dim_base(),
	storage_(_storage)
{}

template<
	typename T,
	typename N,
	typename M,
	typename S
>
fcppt::math::matrix::basic<T, N, M, S>::basic(
	basic const &_other
)
:
	dim_base(
		_other
	),
	storage_(
		_other.storage_
	)
{}

template<
	typename T,
	typename N,
	typename M,
	typename S
>
template<
	typename OtherStorage
>
fcppt::math::matrix::basic<T, N, M, S>::basic(
	basic<
		T,
		N,
		M,
		OtherStorage
	> const &_other
)
:
	dim_base(
		_other
	)
{
	math::detail::initial_size(
		storage_,
		_other.size()
	);

	std::copy(
		_other.begin(),
		_other.end(),
		begin()
	);
}

template<
	typename T,
	typename N,
	typename M,
	typename S
>
template<
	typename In
>
fcppt::math::matrix::basic<T, N, M, S>::basic(
	In const _begin,
	typename boost::enable_if<
		type_traits::is_iterator<
			In
		>,
		In
	>::type const _end
)
:
	dim_base()
{
	std::copy(
		_begin,
		_end,
		begin()
	);
}

template<
	typename T,
	typename N,
	typename M,
	typename S
>
template<
	typename In
>
fcppt::math::matrix::basic<T, N, M, S>::basic(
	dim const &_dim,
	In const _begin,
	typename boost::enable_if<
		type_traits::is_iterator<
			In
		>,
		In
	>::type const _end
)
:
	dim_base(
		_dim
	)
{
	math::detail::initial_size(
		storage_,
		std::distance(
			_begin,
			_end
		)
	);

	std::copy(
		_begin,
		_end,
		begin()
	);
}

template<
        typename T,
        typename N,
        typename M,
        typename S
>
template<
        typename Container
>
fcppt::math::matrix::basic<T, N, M, S>::basic(
        dim const &_dim,
        Container const &_container
)
:
	dim_base(
		_dim
	)
{
	math::detail::initial_size(
		storage_,
		_container.size()
	);

        std::copy(
                _container.begin(),
                _container.end(),
		begin()
        );
}

FCPPT_MATH_DETAIL_ARRAY_ADAPTER_IMPL(
	4,
	(template<typename T, typename N, typename M, typename S>),
	(fcppt::math::matrix::basic<T, N, M, S>)
)

FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR(
	FCPPT_MATH_MATRIX_MAX_CTOR_PARAMS,
	(7, (template<typename T, typename N, typename M, typename S> fcppt::math::matrix::basic<T, N, M, S>::basic))
)

template<
	typename T,
	typename N,
	typename M,
	typename S
>
fcppt::math::matrix::basic<T, N, M, S> &
fcppt::math::matrix::basic<T, N, M, S>::operator=(
	basic const &_other
)
{
	storage_ = _other.storage_;

	return *this;
}

template<
	typename T,
	typename N,
	typename M,
	typename S
>
template<
	typename OtherStorage
>
fcppt::math::matrix::basic<T, N, M, S> &
fcppt::math::matrix::basic<T, N, M, S>::operator=(
	basic<
		T,
		N,
		M,
		OtherStorage
	> const &_other
)
{
	math::detail::initial_size(
		storage_,
		_other.size()
	);

	return
		math::detail::assign(
			*this,
			_other
		);
}

template<
	typename T,
	typename N,
	typename M,
	typename S
>
fcppt::math::matrix::basic<T, N, M, S>::~basic()
{}

// \cond
#define FCPPT_MATH_MATRIX_BASIC_DEFINE_OPERATOR(\
	op\
)\
FCPPT_MATH_DETAIL_MAKE_OP_DEF(\
	4,\
	(template<typename T, typename N, typename M, typename S> template<typename OtherStorage>),\
	(fcppt::math::matrix::basic<T, N, M, S>),\
	(fcppt::math::matrix::basic<T, N, M, OtherStorage>),\
	op\
)
// \endcond

FCPPT_MATH_MATRIX_BASIC_DEFINE_OPERATOR(+=)
FCPPT_MATH_MATRIX_BASIC_DEFINE_OPERATOR(-=)

#undef FCPPT_MATH_MATRIX_BASIC_DEFINE_OPERATOR

template<
	typename T,
	typename N,
	typename M,
	typename S
>
fcppt::math::matrix::basic<T, N, M, S> &
fcppt::math::matrix::basic<T, N, M, S>::operator*=(
	value_type const &_value
)
{
	BOOST_FOREACH(
		value_type &i,
		*this
	)
		i *= _value;

	return *this;
}

template<
	typename T,
	typename N,
	typename M,
	typename S
>
fcppt::math::matrix::basic<T, N, M, S> &
fcppt::math::matrix::basic<T, N, M, S>::operator/=(
	value_type const &_value
)
{
	BOOST_FOREACH(
		value_type &i,
		*this
	)
		i /= _value;

	return *this;
}

template<
	typename T,
	typename N,
	typename M,
	typename S
>
typename fcppt::math::matrix::basic<T, N, M, S>::reference
fcppt::math::matrix::basic<T, N, M, S>::operator[](
	size_type const _j
)
{
	return
		reference(
			typename reference::storage_type(
				data(),
				_j,
				columns(),
				rows()
			)
		);
}

template<
	typename T,
	typename N,
	typename M,
	typename S
>
typename fcppt::math::matrix::basic<T, N, M, S>::const_reference const
fcppt::math::matrix::basic<T, N, M, S>::operator[](
	size_type const _j
) const
{
	return
		const_reference(
			typename const_reference::storage_type(
				data(),
				_j,
				columns(),
				rows()
			)
		);
}

template<
	typename T,
	typename N,
	typename M,
	typename S
>
typename fcppt::math::matrix::basic<T, N, M, S>::pointer
fcppt::math::matrix::basic<T, N, M, S>::data()
{
	return
		math::detail::storage_data(
			storage_
		);
}

template<
	typename T,
	typename N,
	typename M,
	typename S
>
typename fcppt::math::matrix::basic<T, N, M, S>::const_pointer
fcppt::math::matrix::basic<T, N, M, S>::data() const
{
	return
		const_cast<
			basic &
		>(
			*this
		).data();
}

template<
	typename T,
	typename N,
	typename M,
	typename S
>
typename fcppt::math::matrix::basic<T, N, M, S>::size_type
fcppt::math::matrix::basic<T, N, M, S>::size() const
{
	return
		static_cast<
			size_type
		>(
			math::detail::storage_dim(
				storage_
			)
		);
}
template<
	typename T,
	typename N,
	typename M,
	typename S
>
typename fcppt::math::matrix::basic<T, N, M, S>::size_type
fcppt::math::matrix::basic<T, N, M, S>::rows() const
{
	return dim_base::rows();
}

template<
	typename T,
	typename N,
	typename M,
	typename S
>
typename fcppt::math::matrix::basic<T, N, M, S>::size_type
fcppt::math::matrix::basic<T, N, M, S>::columns() const
{
	return dim_base::columns();
}

template<
	typename T,
	typename N,
	typename M,
	typename S
>
typename fcppt::math::matrix::basic<T, N, M, S>::dim const
fcppt::math::matrix::basic<T, N, M, S>::dimension() const
{
	return
		dim(
			columns(),
			rows()
		);
}

template<
	typename T,
	typename N,
	typename M,
	typename S
>
fcppt::math::matrix::basic<T, N, M, S> const
fcppt::math::matrix::basic<T, N, M, S>::identity()
{
	basic<T, N, M, S> ret;
	for(size_type i = 0; i < N::value; ++i)
		for(size_type j = 0; j < M::value; ++j)
			ret[i][j] =
				i == j
				? static_cast<T>(1)
				: static_cast<T>(0);
	return ret;
}

template<
	typename T,
	typename N,
	typename M,
	typename S
>
void
fcppt::math::matrix::basic<T, N, M, S>::swap(
	basic &_other
)
{
	std::swap(
		storage_,
		_other.storage_
	);

	dim_base::swap(
		_other
	);
}

template<
	typename T,
	typename N,
	typename M,
	typename S
>
void
fcppt::math::matrix::swap(
	basic<T, N, M, S> &_a,
	basic<T, N, M, S> &_b
)
{
	_a.swap(
		_b
	);
}

#endif
