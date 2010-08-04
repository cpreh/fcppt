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
	dim const &dim_
)
:
	dim_base(
		dim_
	)
{}

template<
	typename T,
	typename N,
	typename M,
	typename S
>
fcppt::math::matrix::basic<T, N, M, S>::basic(
	storage_type const &storage
)
:
	dim_base(),
	storage(storage)
{}

template<
	typename T,
	typename N,
	typename M,
	typename S
>
fcppt::math::matrix::basic<T, N, M, S>::basic(
	basic const &other_
)
:
	dim_base(
		other_
	),
	storage(other_.storage)
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
	> const &other_
)
:
	dim_base(
		other_
	)
{
	math::detail::initial_size(
		storage,
		other_.size()
	);

	std::copy(
		other_.begin(),
		other_.end(),
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
	In const beg,
	typename boost::enable_if<
		type_traits::is_iterator<
			In
		>,
		In
	>::type const end
)
:
	dim_base()
{
	std::copy(
		beg,
		end,
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
	dim const &dim_,
	In const beg,
	typename boost::enable_if<
		type_traits::is_iterator<
			In
		>,
		In
	>::type const end
)
:
	dim_base(
		dim_
	)
{
	math::detail::initial_size(
		storage,
		std::distance(
			beg,
			end
		)
	);

	std::copy(
		beg,
		end,
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
        dim const &dim_,
        Container const &container_
)
:
	dim_base(
		dim_
	)
{
	math::detail::initial_size(
		storage,
		container_.size()
	);

        std::copy(
                container_.begin(),
                container_.end(),
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
	basic const &other_
)
{
	storage = other_.storage;

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
	> const &other_
)
{
	math::detail::initial_size(
		storage,
		other_.size()
	);

	return
		math::detail::assign(
			*this,
			other_
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
	value_type const &v
)
{
	BOOST_FOREACH(
		value_type &i,
		*this
	)
		i *= v;

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
	value_type const &v
)
{
	BOOST_FOREACH(
		value_type &i,
		*this
	)
		i /= v;

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
	size_type const j
)
{
	return
		reference(
			typename reference::storage_type(
				data(),
				j,
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
	size_type const j
) const
{
	return
		const_reference(
			typename const_reference::storage_type(
				data(),
				j,
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
			storage
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
				storage
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
	return dim(
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
	basic &other_
)
{
	std::swap(
		storage,
		other_.storage
	);

	dim_base::swap(
		other_
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
	basic<T, N, M, S> &a,
	basic<T, N, M, S> &b
)
{
	return a.swap(b);
}

#endif
