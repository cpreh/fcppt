//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_OBJECT_DECL_HPP_INCLUDED

#include <fcppt/no_init_fwd.hpp>
#include <fcppt/math/difference_type.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/static_size.hpp>
#include <fcppt/math/matrix/object_fwd.hpp>
#include <fcppt/math/matrix/row_type_fwd.hpp>
#include <fcppt/math/matrix/detail/row_view_fwd.hpp>
#include <fcppt/math/vector/object_decl.hpp>


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
	fcppt::math::static_size<
		static_rows::value
		*
		static_columns::value
	>
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
	\brief A reference to a row of the matrix.
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
	\brief A reference to an element of the matrix.
	*/
	typedef
	typename
	reference::reference
	inner_reference;

	/**
	\brief A const reference to a row of the matrix.
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
	\brief A const reference to an element of the matrix.
	*/
	typedef
	typename
	const_reference::const_reference
	const_inner_reference;

	/**
	\brief The type of a row, which is a vector of <code>C</code> elements.
	*/
	typedef
	fcppt::math::matrix::row_type<
		T,
		C
	>
	row_type;

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
	fcppt::math::matrix::object::row_type\endlink. You can use
	\link fcppt::math::matrix::row\endlink to create them.
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

	template<
		typename S2
	>
	object &
	operator+=(
		object<
			T,
			R,
			C,
			S2
		> const &
	);

	template<
		typename S2
	>
	object &
	operator-=(
		object<
			T,
			R,
			C,
			S2
		> const &
	);

	/**
	\brief Multiply a matrix by a scalar
	*/
	object &
	operator*=(
		value_type const &
	);

	/**
	\brief Returns a reference to a row in the matrix

	\warning
	Behaviour is undefined if the index is out of range.
	*/
	reference
	get_unsafe(
		size_type
	);

	/**
	\brief Returns a reference to a (constant) row in the matrix

	\warning
	Behaviour is undefined if the index is out of range.
	*/
	const_reference
	get_unsafe(
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

	inner_reference
	m00();

	const_inner_reference
	m00() const;

	inner_reference
	m01();

	const_inner_reference
	m01() const;

	inner_reference
	m02();

	const_inner_reference
	m02() const;

	inner_reference
	m03();

	const_inner_reference
	m03() const;

	inner_reference
	m10();

	const_inner_reference
	m10() const;

	inner_reference
	m11();

	const_inner_reference
	m11() const;

	inner_reference
	m12();

	const_inner_reference
	m12() const;

	inner_reference
	m13();

	const_inner_reference
	m13() const;

	inner_reference
	m20();

	const_inner_reference
	m20() const;

	inner_reference
	m21();

	const_inner_reference
	m21() const;

	inner_reference
	m22();

	const_inner_reference
	m22() const;

	inner_reference
	m23();

	const_inner_reference
	m23() const;

	inner_reference
	m30();

	const_inner_reference
	m30() const;

	inner_reference
	m31();

	const_inner_reference
	m31() const;

	inner_reference
	m32();

	const_inner_reference
	m32() const;

	inner_reference
	m33();

	const_inner_reference
	m33() const;
private:
	S storage_;
};

}
}
}

#endif
