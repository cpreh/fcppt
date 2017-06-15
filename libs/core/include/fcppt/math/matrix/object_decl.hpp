//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_OBJECT_DECL_HPP_INCLUDED

#include <fcppt/no_init_fwd.hpp>
#include <fcppt/math/difference_type.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/make_op_decl.hpp>
#include <fcppt/math/matrix/object_fwd.hpp>
#include <fcppt/math/matrix/detail/row_view_fwd.hpp>
#include <fcppt/math/vector/object_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/times.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{

/**
\brief A class representing a static matrix

Represents a static <code>R</code> by <code>C</code> matrix, which is a matrix
consisting of <code>R</code> rows and <code>C</code> columns.

\ingroup fcpptmathmatrix

\tparam T The matrix's <code>value_type</code>

\tparam R The number of rows

\tparam C The number of columns

\tparam S The matrix's storage type

See the \link fcpptmathmatrix module documentation \endlink for more information.
*/
template<
	typename T,
	fcppt::math::size_type R,
	fcppt::math::size_type C,
	typename S
>
class object
{
public:
	typedef
	fcppt::math::static_size<
		R
	>
	static_rows;

	typedef
	fcppt::math::static_size<
		C
	>
	static_columns;

	typedef
	static_rows
	static_size;

	typedef
	typename
	boost::mpl::times<
		static_rows,
		static_columns
	>::type
	dim_wrapper;

	/**
	\brief A typedef for the \p S parameter
	*/
	typedef
	S
	storage_type;

	/**
	\brief A type that counts the number of elements in a matrix.
	*/
	typedef
	fcppt::math::size_type
	size_type;

	/**
	\brief A type that provides the difference between the addresses of two elements in a matrix.
	*/
	typedef
	fcppt::math::difference_type
	difference_type;

	/**
	\brief A type that represents the data type stored in a matrix.
	*/
	typedef
	T
	value_type;

	/**
	\brief A type that provides a reference to an element stored in a
	matrix.

	This is one of the few non-trivial implementations of the reference
	typedef, as it's really a vector that models a row-view over the
	matrix.
	*/
	typedef
	fcppt::math::vector::object<
		T,
		C,
		fcppt::math::matrix::detail::row_view<
			T,
			C
		>
	>
	reference;

	/**
	\brief
	A type that provides a reference to a <code>const</code> element stored
	in a vector for reading and performing <code>const</code> operations.

	This is one of the few non-trivial implementations of the reference
	typedef, as it's really a vector that models a row-view over the
	matrix.
	*/
	typedef
	fcppt::math::vector::object<
		T,
		C,
		fcppt::math::matrix::detail::row_view<
			T const,
			C
		>
	>
	const_reference;

	/**
	\brief Construct an uninitialized matrix

	\warning
	The content of the matrix will be undefined (not null) after
	initialization
	*/
	explicit
	object(
		fcppt::no_init const &
	);

	/**
	\brief Construct a matrix from a storage source
	*/
	explicit
	object(
		storage_type const &
	);

	/**
	\brief Constructs a matrix from <code>R</code> rows

	Constructs a matrix by using <code>R</code> arguments of type \link
	fcppt::math::matrix::row_type\endlink of size <code>C</code>. Use \link
	fcppt::math::matrix::row\endlink to initialize them.
	*/
	template<
		typename ...Args
	>
	explicit
	object(
		Args const &...
	);

	/**
	\brief Copy-construct the matrix from another matrix
	*/
	object(
		object const &
	);

	/**
	\brief Create a matrix from a matrix with the same dimension and value
	type but different storage type

	\tparam OtherStorage The other matrix's storage type
	*/
	template<
		typename OtherStorage
	>
	explicit
	object(
		fcppt::math::matrix::object<
			T,
			R,
			C,
			OtherStorage
		> const &
	);

	/**
	\brief Copy the values from a different matrix
	*/
	object &
	operator=(
		object const &
	);

	/**
	\brief Copy the values from a different matrix of the same size but
	different storage type

	\tparam OtherStorage The other matrix's storage type
	*/
	template<
		typename OtherStorage
	>
	object &
	operator=(
		fcppt::math::matrix::object<
			T,
			R,
			C,
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
	(object<T, R, C, OtherStorage>),\
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
	const_reference
	operator[](
		size_type
	) const;

	/**
	\brief Returns the number of rows in the matrix.
	*/
	constexpr
	static
	size_type
	rows();

	/**
	\brief Returns the number of columns in the matrix.
	*/
	constexpr
	static
	size_type
	columns();

	S &
	storage();

	S const &
	storage() const;
private:
	S storage_;
};

}
}
}

#endif
