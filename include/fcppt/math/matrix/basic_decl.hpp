//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_BASIC_DECL_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_BASIC_DECL_HPP_INCLUDED

#include <fcppt/math/difference_type.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/make_op_decl.hpp>
#include <fcppt/math/detail/make_variadic_constructor_decl.hpp>
#include <fcppt/math/matrix/basic_fwd.hpp>
#include <fcppt/math/matrix/dim_type.hpp>
#include <fcppt/math/matrix/max_ctor_params.hpp>
#include <fcppt/math/matrix/detail/dim_storage.hpp>
#include <fcppt/math/matrix/detail/row_view.hpp>
#include <fcppt/math/vector/basic_decl.hpp>
#include <fcppt/type_traits/is_iterator.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/static_assert.hpp>
#include <boost/mpl/times.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/utility/enable_if.hpp>
#include <iterator>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{

/**
\brief A class representing dynamic or static matrices
\ingroup fcpptmathmatrix
\tparam T The matrix's <code>value_type</code>
\tparam N The matrix's row type (this is not necessarily a number!)
\tparam M The matrix's column type (this is not necessarily a number!)
\tparam S The matrix's storage type
\ingroup fcpptmathdim

See the \link fcpptmathmatrix module documentation \endlink for more information.
*/
template<
	typename T,
	typename N,
	typename M,
	typename S
>
class basic
/// \cond
:
private
	detail::dim_storage<
		N,
		M
	>
/// \endcond
{
	typedef detail::dim_storage<N, M> dim_base;
public:
	BOOST_STATIC_ASSERT((
		boost::is_same<
			typename N::value_type,
			typename M::value_type
		>::value
	));

	/**
	\brief A typedef for the \p M and \p N parameters
	*/
	typedef typename boost::mpl::times<
		N,
		M
	>::type dim_wrapper;

	/**
	\brief A typedef for the \p S parameter
	*/
	typedef S storage_type;

	/**
	\brief A type that counts the number of elements in a matrix.
	*/
	typedef math::size_type size_type;
	/**
	\brief A type that provides the difference between the addresses of two elements in a matrix.
	*/
	typedef math::difference_type difference_type;

	/**
	\brief A type that represents the data type stored in a matrix.
	*/
	typedef T value_type;

	/**
	\brief A type that provides a reference to an element stored in a matrix.

	This is one of the few non-trivial implementations of the reference
	typedef, as it's really a vector that models a row-view over the
	matrix, see the explanation above.
	*/
	typedef vector::basic<
		T,
		N,
		matrix::detail::row_view<
			T,
			N
		>
	> reference;

	/**
	\brief
	A type that provides a reference to a <code>const</code> element stored
	in a vector for reading and performing <code>const</code> operations.

	This is one of the few non-trivial implementations of the reference
	typedef, as it's really a vector that models a row-view over the
	matrix, see the explanation above.
	*/
	typedef vector::basic<
		T,
		N,
		matrix::detail::row_view<
			T const,
			N
		>
	> const_reference;

	/**
	\brief A type that provides a pointer to an element in a matrix.
	*/
	typedef T *pointer;

	/**
	\brief A type that provides a pointer to a <code>const</code> element in a matrix.
	*/
	typedef T const *const_pointer;

	/**
	\brief A type that provides a random-access iterator that can read or modify any element in a matrix.

	\warning
	An "element" in this case is <em>not</em> a row, but a single cell. See the iteration section above.
	*/
	typedef pointer iterator;

	/**
	\brief A type that provides a random-access iterator that can read or modify any element in a matrix.

	\warning
	An "element" in this case is <em>not</em> a row, but a single cell. See the iteration section above.
	*/
	typedef const_pointer const_iterator;

	/**
	\brief A type that provides a random-access iterator that can read or modify any element in a reversed matrix.
	*/
	typedef std::reverse_iterator<iterator> reverse_iterator;

	/**
	\brief A type that provides a random-access iterator that can read any <code>const</code> element in the matrix.
	*/
	typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

	/**
	\brief The dim type corresponding to this matrix type.
	*/
	typedef matrix::dim_type dim;

	/**
	\brief Construct an uninitialized matrix

	\warning
	The content of the vector will be undefined (not null) after
	initialization
	*/
	basic();

	/**
	\brief Construct an uninitialized dynamic matrix

	\warning
	This operation makes no sense on a static matrix.
	*/
	explicit basic(
		dim const &
	);

	/**
	\brief Construct a vector from a storage source
	\param s The storage source to copy from
	*/
	explicit basic(
		storage_type const &s
	);

	/**
	\brief Copy-construct the matrix from another matrix
	*/
	basic(
		basic const &
	);

	/**
	\brief Create a matrix from a matrix with the same dimension and value type but different storage type
	\tparam OtherStorage The other matrix's storage type
	*/
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

	/**
	\brief Create a matrix and fill it with the contents of the given range
	\tparam In A forward iterator pointing to elements of type <code>T</code>
	\param beg The beginning of the range
	\param end One past the end of the range
	*/
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

	/**
	\brief Create a dynamic matrix and fill it with the contents of the given range
	\tparam In A forward iterator pointing to elements of type <code>T</code>
	\param _dim The two-dimensional dimension corresponding to the one-dimensional range
	\param beg The beginning of the range
	\param end One past the end of the range

	\warning
	This operation makes no sense on a static matrix.
	*/
	template<
		typename In
	>
	basic(
		dim const &_dim,
		In beg,
		typename boost::enable_if<
			type_traits::is_iterator<
				In
			>,
			In
		>::type end
	);

	/**
	\brief Create a dynamic matrix and fill it with the contents of a range
	\tparam Container A sequence container containing elements of type <code>T</code>

	\warning
	This operation makes no sense on a static matrix.
	*/
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

	/**
	\brief Copy the values from a different matrix
	*/
	basic &
	operator=(
		basic const &
	);

	/**
	\brief Copy the values from a different matrix of the same size but different storage type
	\tparam OtherStorage The other matrix's storage type
	*/
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

// \cond FCPPT_DOXYGEN_DEBUG
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

	/**
	\brief Multiply a matrix by a scalar
	*/
	basic &
	operator*=(
		value_type const &
	);

	/**
	\brief Divide a matrix by a scalar
	*/
	basic &
	operator/=(
		value_type const &
	);

	/**
	\brief Returns a reference to a row in the matrix

	\warning
	Behaviour is undefined if the index is out of range.
	*/
	reference
	operator[](
		size_type
	);

	/**
	\brief Returns a reference to a (constant) row in the matrix

	\warning
	Behaviour is undefined if the index is out of range.
	*/
	const_reference const
	operator[](
		size_type
	) const;

	/**
	\brief Returns the pointer to the store.
	*/
	pointer
	data();

	/**
	\brief Returns the pointer to the store.
	*/
	const_pointer
	data() const;

	/**
	\brief Returns the number of elements in the matrix.
	*/
	size_type
	size() const;

	/**
	\brief Returns the number of rows in the matrix.
	*/
	size_type
	rows() const;

	/**
	\brief Returns the number of columns in the matrix.
	*/
	size_type
	columns() const;

	/**
	\brief Returns the matrix's dimensions.
	*/
	dim const
	dimension() const;

	/**
	\brief Returns the identity matrix;
	*/
	static basic const
	identity();

	/**
	\brief Exchanges the elements of two matrices.
	*/
	void
	swap(
		basic &
	);
private:
	S storage_;
};

/**
\brief Exchanges the elements of two matrices.
*/
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
