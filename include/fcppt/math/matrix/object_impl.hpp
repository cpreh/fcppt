//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_OBJECT_IMPL_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_OBJECT_IMPL_HPP_INCLUDED

#include <fcppt/static_assert_expression.hpp>
#include <fcppt/math/detail/array_adapter_impl.hpp>
#include <fcppt/math/detail/assign.hpp>
#include <fcppt/math/detail/initial_size.hpp>
#include <fcppt/math/detail/make_op_def.hpp>
#include <fcppt/math/detail/make_variadic_constructor.hpp>
#include <fcppt/math/dim/object_impl.hpp>
#include <fcppt/math/matrix/is_static_size.hpp>
#include <fcppt/math/matrix/object_decl.hpp>
#include <fcppt/math/matrix/detail/dim_storage_impl.hpp>
#include <fcppt/math/matrix/detail/row_view_impl.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <iterator>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)
template<
	typename T,
	typename N,
	typename M,
	typename S
>
fcppt::math::matrix::object<T, N, M, S>::object()
:
	dim_base()
// Don't initialize storage_()
{
	FCPPT_STATIC_ASSERT_EXPRESSION((
		fcppt::math::matrix::is_static_size<
			N,
			M
		>::value
	));
}

template<
	typename T,
	typename N,
	typename M,
	typename S
>
fcppt::math::matrix::object<T, N, M, S>::object(
	dim const &_dim
)
:
	dim_base(
		_dim
	)
// Don't initialize storage_()
{
	// This constructor has no effect on static matrices
}

FCPPT_PP_POP_WARNING

template<
	typename T,
	typename N,
	typename M,
	typename S
>
fcppt::math::matrix::object<T, N, M, S>::object(
	storage_type const &_storage
)
:
	dim_base(),
	storage_(
		_storage
	)
{
	FCPPT_STATIC_ASSERT_EXPRESSION((
		fcppt::math::matrix::is_static_size<
			N,
			M
		>::value
	));
}

template<
	typename T,
	typename N,
	typename M,
	typename S
>
fcppt::math::matrix::object<T, N, M, S>::object(
	object const &_other
)
:
	dim_base(
		_other
	),
	storage_(
		_other.storage_
	)
{
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename T,
	typename N,
	typename M,
	typename S
>
template<
	typename OtherStorage
>
fcppt::math::matrix::object<T, N, M, S>::object(
	object<
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
// Don't initialize storage_()
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
fcppt::math::matrix::object<T, N, M, S>::object(
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
// Don't initialize storage_()
{
	FCPPT_STATIC_ASSERT_EXPRESSION((
		fcppt::math::matrix::is_static_size<
			N,
			M
		>::value
	));

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
fcppt::math::matrix::object<T, N, M, S>::object(
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
// Don't initialize storage_()
{
	FCPPT_STATIC_ASSERT_EXPRESSION((
		!fcppt::math::matrix::is_static_size<
			N,
			M
		>::value
	));

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
fcppt::math::matrix::object<T, N, M, S>::object(
	dim const &_dim,
	Container const &_container
)
:
	dim_base(
		_dim
	)
// Don't initialize storage_()
{
	FCPPT_STATIC_ASSERT_EXPRESSION((
		!fcppt::math::matrix::is_static_size<
			N,
			M
		>::value
	));

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

FCPPT_PP_POP_WARNING

FCPPT_MATH_DETAIL_ARRAY_ADAPTER_IMPL(
	4,
	(template<typename T, typename N, typename M, typename S>),
	(fcppt::math::matrix::object<T, N, M, S>)
)

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR(
	FCPPT_MATH_MATRIX_MAX_CTOR_PARAMS,
	(7, (template<typename T, typename N, typename M, typename S> fcppt::math::matrix::object<T, N, M, S>::object))
)

FCPPT_PP_POP_WARNING

template<
	typename T,
	typename N,
	typename M,
	typename S
>
fcppt::math::matrix::object<T, N, M, S> &
fcppt::math::matrix::object<T, N, M, S>::operator=(
	object const &_other
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
fcppt::math::matrix::object<T, N, M, S> &
fcppt::math::matrix::object<T, N, M, S>::operator=(
	object<
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
fcppt::math::matrix::object<T, N, M, S>::~object()
{}

// \cond FCPPT_DOXYGEN_DEBUG
#define FCPPT_MATH_MATRIX_OBJECT_DEFINE_OPERATOR(\
	op\
)\
FCPPT_MATH_DETAIL_MAKE_OP_DEF(\
	4,\
	(template<typename T, typename N, typename M, typename S> template<typename OtherStorage>),\
	(fcppt::math::matrix::object<T, N, M, S>),\
	(fcppt::math::matrix::object<T, N, M, OtherStorage>),\
	op\
)
// \endcond

FCPPT_MATH_MATRIX_OBJECT_DEFINE_OPERATOR(+=)
FCPPT_MATH_MATRIX_OBJECT_DEFINE_OPERATOR(-=)

#undef FCPPT_MATH_MATRIX_OBJECT_DEFINE_OPERATOR

template<
	typename T,
	typename N,
	typename M,
	typename S
>
fcppt::math::matrix::object<T, N, M, S> &
fcppt::math::matrix::object<T, N, M, S>::operator*=(
	value_type const &_value
)
{
	for(
		iterator it(
			this->begin()
		);
		it != this->end();
		++it
	)
		*it *= _value;

	return *this;
}

template<
	typename T,
	typename N,
	typename M,
	typename S
>
fcppt::math::matrix::object<T, N, M, S> &
fcppt::math::matrix::object<T, N, M, S>::operator/=(
	value_type const &_value
)
{
	for(
		iterator it(
			this->begin()
		);
		it != this->end();
		++it
	)
		*it /= _value;

	return *this;
}

template<
	typename T,
	typename N,
	typename M,
	typename S
>
typename fcppt::math::matrix::object<T, N, M, S>::reference
fcppt::math::matrix::object<T, N, M, S>::operator[](
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
typename fcppt::math::matrix::object<T, N, M, S>::const_reference const
fcppt::math::matrix::object<T, N, M, S>::operator[](
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
typename fcppt::math::matrix::object<T, N, M, S>::size_type
fcppt::math::matrix::object<T, N, M, S>::rows() const
{
	return dim_base::rows();
}

template<
	typename T,
	typename N,
	typename M,
	typename S
>
typename fcppt::math::matrix::object<T, N, M, S>::size_type
fcppt::math::matrix::object<T, N, M, S>::columns() const
{
	return dim_base::columns();
}

template<
	typename T,
	typename N,
	typename M,
	typename S
>
typename fcppt::math::matrix::object<T, N, M, S>::dim const
fcppt::math::matrix::object<T, N, M, S>::dimension() const
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
fcppt::math::matrix::object<T, N, M, S> const
fcppt::math::matrix::object<T, N, M, S>::identity()
{
	object<T, N, M, S> ret;
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
fcppt::math::matrix::object<T, N, M, S>::swap(
	object &_other
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
	object<T, N, M, S> &_a,
	object<T, N, M, S> &_b
)
{
	_a.swap(
		_b
	);
}

#endif
