//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_OBJECT_DECL_HPP_INCLUDED

#include <fcppt/no_init_fwd.hpp>
#include <fcppt/math/difference_type.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/make_op_decl.hpp>
#include <fcppt/math/detail/make_variadic_constructor_decl.hpp>
#include <fcppt/math/matrix/max_ctor_params.hpp>
#include <fcppt/math/matrix/object_fwd.hpp>
#include <fcppt/math/matrix/static_storage.hpp>
#include <fcppt/math/matrix/detail/row_view_fwd.hpp>
#include <fcppt/math/vector/object_decl.hpp>
#include <fcppt/type_traits/is_iterator.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/times.hpp>
#include <boost/utility/enable_if.hpp>
#include <iterator>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{

/**
\brief A class representing a static matrix
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
class object
{
public:
	static_assert(
		std::is_same<
			typename N::value_type,
			typename M::value_type
		>::value,
		"The value types of N and M must be the same"
	);

	/**
	\brief A typedef for the \p N parameter
	*/
	typedef N n_wrapper;

	/**
	\brief A typedef for the \p M parameter
	*/
	typedef M m_wrapper;

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
	typedef fcppt::math::size_type size_type;
	/**
	\brief A type that provides the difference between the addresses of two elements in a matrix.
	*/
	typedef fcppt::math::difference_type difference_type;

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
	typedef fcppt::math::vector::object<
		T,
		N,
		fcppt::math::matrix::detail::row_view<
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
	typedef fcppt::math::vector::object<
		T,
		N,
		fcppt::math::matrix::detail::row_view<
			T const,
			N
		>
	> const_reference;

	/**
	\brief A type that provides a pointer to an element in a matrix.
	*/
	typedef typename storage_type::pointer pointer;

	/**
	\brief A type that provides a pointer to a <code>const</code> element in a matrix.
	*/
	typedef typename storage_type::const_pointer const_pointer;

	/**
	\brief A type that provides a random-access iterator that can read or modify any element in a matrix.

	\warning
	An "element" in this case is <em>not</em> a row, but a single cell. See the iteration section above.
	*/
	typedef typename storage_type::iterator iterator;

	/**
	\brief A type that provides a random-access iterator that can read or modify any element in a matrix.

	\warning
	An "element" in this case is <em>not</em> a row, but a single cell. See the iteration section above.
	*/
	typedef typename storage_type::const_iterator const_iterator;

	/**
	\brief A type that provides a random-access iterator that can read or modify any element in a reversed matrix.
	*/
	typedef std::reverse_iterator<iterator> reverse_iterator;

	/**
	\brief A type that provides a random-access iterator that can read any <code>const</code> element in the matrix.
	*/
	typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

	/**
	\brief Calls the default constructor for every element
	*/
	object();

	/**
	\brief Construct an uninitialized matrix

	\warning
	The content of the vector will be undefined (not null) after
	initialization
	*/
	explicit
	object(
		fcppt::no_init const &
	);

	/**
	\brief Construct a vector from a storage source
	\param s The storage source to copy from
	*/
	explicit
	object(
		storage_type const &s
	);

	/**
	\brief Copy-construct the matrix from another matrix
	*/
	object(
		object const &
	);

	/**
	\brief Create a matrix from a matrix with the same dimension and value type but different storage type
	\tparam OtherStorage The other matrix's storage type
	*/
	template<
		typename OtherStorage
	>
	object(
		fcppt::math::matrix::object<
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
	object(
		In beg,
		typename boost::enable_if<
			fcppt::type_traits::is_iterator<
				In
			>,
			In
		>::type end
	);

	FCPPT_MATH_DETAIL_ARRAY_ADAPTER(
		object
	)

	FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR_DECL(
		FCPPT_MATH_MATRIX_MAX_CTOR_PARAMS,
		object
	)

	/**
	\brief Copy the values from a different matrix
	*/
	object &
	operator=(
		object const &
	);

	/**
	\brief Copy the values from a different matrix of the same size but different storage type
	\tparam OtherStorage The other matrix's storage type
	*/
	template<
		typename OtherStorage
	>
	object &
	operator=(
		fcppt::math::matrix::object<
			T,
			N,
			M,
			OtherStorage
		> const &
	);

	~object();

// \cond FCPPT_DOXYGEN_DEBUG
#define FCPPT_MATH_MATRIX_OBJECT_DECLARE_OPERATOR(op)\
FCPPT_MATH_DETAIL_MAKE_OP_DECL(\
	template<\
		typename OtherStorage\
	>, \
	(object<T, N, M, OtherStorage>),\
	4,\
	op \
)
// \endcond

	FCPPT_MATH_MATRIX_OBJECT_DECLARE_OPERATOR(+=)
	FCPPT_MATH_MATRIX_OBJECT_DECLARE_OPERATOR(-=)
#undef FCPPT_MATH_MATRIX_OBJECT_DECLARE_OPERATOR

	/**
	\brief Multiply a matrix by a scalar
	*/
	object &
	operator*=(
		value_type const &
	);

	/**
	\brief Divide a matrix by a scalar
	*/
	object &
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
	\brief Returns the number of rows in the matrix.
	*/
	static
	size_type
	rows();

	/**
	\brief Returns the number of columns in the matrix.
	*/
	static
	size_type
	columns();

	/**
	\brief Returns the identity matrix;
	*/
	static
	fcppt::math::matrix::object<
		T,
		N,
		M,
		typename fcppt::math::matrix::static_storage<
			T,
			N,
			M
		>::type
	> const
	identity();

	/**
	\brief Exchanges the elements of two matrices.
	*/
	void
	swap(
		object &
	);

	S const &
	storage() const;
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
	fcppt::math::matrix::object<
		T,
		N,
		M,
		S
	> &,
	fcppt::math::matrix::object<
		T,
		N,
		M,
		S
	> &
);

}
}
}

#endif
