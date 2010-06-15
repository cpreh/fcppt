//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_BASIC_DECL_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_BASIC_DECL_HPP_INCLUDED

#include <fcppt/math/matrix/basic_fwd.hpp>
#include <fcppt/math/matrix/max_ctor_params.hpp>
#include <fcppt/math/matrix/dim_type.hpp>
#include <fcppt/math/matrix/detail/dim_storage.hpp>
#include <fcppt/math/detail/view_storage.hpp>
#include <fcppt/math/detail/make_op_decl.hpp>
#include <fcppt/math/detail/make_variadic_constructor_decl.hpp>
#include <fcppt/math/vector/basic_decl.hpp>
#include <fcppt/type_traits/is_iterator.hpp>
#include <boost/mpl/times.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/static_assert.hpp>
#include <iterator>

namespace fcppt
{
namespace math
{
namespace matrix
{

template<
	typename T,
	typename N,
	typename M,
	typename S
>
class basic
:
private
	detail::dim_storage<
		N,
		M
	>
{
	typedef detail::dim_storage<N, M> dim_base;
public:
	BOOST_STATIC_ASSERT((
		boost::is_same<
			typename N::value_type,
			typename M::value_type
		>::value
	));

	typedef typename boost::mpl::times<
		N,
		M
	>::type dim_wrapper;

	typedef S storage_type;

	typedef typename N::value_type size_type;

	typedef T value_type;

	typedef vector::basic<
		T,
		N,
		math::detail::view_storage<
			T,
			N
		>
	> reference;

	typedef vector::basic<
		T,
		N,
		math::detail::view_storage<
			T const,
			N
		>
	> const_reference;

	typedef T *pointer;

	typedef T const *const_pointer;

	typedef pointer iterator;

	typedef const_pointer const_iterator;

	typedef std::reverse_iterator<iterator> reverse_iterator;

	typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

	typedef matrix::dim_type dim;

	basic();

	explicit basic(
		dim const &
	);

	explicit basic(
		storage_type const &
	);

	basic(
		basic const &
	);

	template<
		typename OtherStorage
	>
	basic(
		basic<
			T,
			N,
			M,
			OtherStorage
		> const &
	);

	template<
		typename In
	>
	basic(
		In beg,
		typename boost::enable_if<
			type_traits::is_iterator<
				In
			>,
			In
		>::type end
	);

	template<
		typename In
	>
	basic(
		dim const &,
		In beg,
		typename boost::enable_if<
			type_traits::is_iterator<
				In
			>,
			In
		>::type end
	);

	template<
		typename Container
	>
	basic(
		dim const &,
		Container const &
	);

	FCPPT_MATH_DETAIL_ARRAY_ADAPTER(
		basic
	)

	FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR_DECL(
		FCPPT_MATH_MATRIX_MAX_CTOR_PARAMS,
		basic
	)

	basic &
	operator=(
		basic const &
	);

	template<
		typename OtherStorage
	>
	basic &
	operator=(
		basic<
			T,
			N,
			M,
			OtherStorage
		> const &
	);

	~basic();

// \cond
#define FCPPT_MATH_MATRIX_BASIC_DECLARE_OPERATOR(op)\
FCPPT_MATH_DETAIL_MAKE_OP_DECL(\
	template<\
		typename OtherStorage\
	>, \
	(basic<T, N, M, OtherStorage>),\
	4,\
	op \
)
// \endcond

	FCPPT_MATH_MATRIX_BASIC_DECLARE_OPERATOR(+=)
	FCPPT_MATH_MATRIX_BASIC_DECLARE_OPERATOR(-=)
#undef FCPPT_MATH_MATRIX_BASIC_DECLARE_OPERATOR

	basic &
	operator*=(
		value_type const &
	);

	basic &
	operator/=(
		value_type const &
	);

	reference
	operator[](
		size_type
	);

	const_reference const
	operator[](
		size_type
	) const;

	pointer
	data();

	const_pointer
	data() const;

	size_type
	size() const;

	size_type
	rows() const;

	size_type
	columns() const;

	dim const
	dimension() const;

	static basic const
	identity();

	void
	swap(
		basic &
	);
private:
	S storage;
};

template<
	typename T,
	typename N,
	typename M,
	typename S
>
void
swap(
	basic<T, N, M, S> &,
	basic<T, N, M, S> &
);

}
}
}

#endif
