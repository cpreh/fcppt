//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_OBJECT_DECL_HPP_INCLUDED

#include <fcppt/no_init_fwd.hpp>
#include <fcppt/math/difference_type.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/static_storage.hpp>
#include <fcppt/math/detail/array_adapter.hpp>
#include <fcppt/math/detail/make_op_decl.hpp>
#include <fcppt/math/vector/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iterator>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace vector
{

/**
\brief A class representing static n-dimensional vectors
\tparam T The vector's <code>value_type</code>
\tparam N The vector's dimension type
\tparam S The vector's storage type
\ingroup fcpptmathvector

See the \link fcpptmathvector module documentation \endlink for more information.
*/
template<
	typename T,
	typename N,
	typename S
>
class object
{
public:
	/**
	\brief A typedef for the \p N parameter
	*/
	typedef N dim_wrapper;

	typedef N static_size;

	/**
	\brief A typedef for the \p S parameter
	*/
	typedef S storage_type;

	/**
	\brief A type that counts the number of elements in a vector.
	*/
	typedef fcppt::math::size_type size_type;
	/**
	\brief A type that provides the difference between the addresses of two elements in a vector.
	*/
	typedef fcppt::math::difference_type difference_type;
	/**
	\brief A type that represents the data type stored in a vector.
	*/
	typedef T value_type;
	/**
	\brief A type that provides a reference to an element stored in a vector.
	*/
	typedef typename storage_type::reference reference;
	/**
	\brief A type that provides a reference to a <code>const</code> element stored in a vector for reading and performing <code>const</code> operations.
	*/
	typedef typename storage_type::const_reference const_reference;
	/**
	\brief A type that provides a pointer to an element in a vector.
	*/
	typedef typename storage_type::pointer pointer;
	/**
	\brief A type that provides a pointer to a <code>const</code> element in a vector.
	*/
	typedef typename storage_type::const_pointer const_pointer;
	/**
	\brief A type that provides a random-access iterator that can read or modify any element in a vector.
	*/
	typedef typename storage_type::iterator iterator;
	/**
	\brief A type that provides a random-access iterator that can read a <code>const</code> element in a vector.
	*/
	typedef typename storage_type::const_iterator const_iterator;
	/**
	\brief A type that provides a random-access iterator that can read or modify any element in a reversed vector.
	*/
	typedef std::reverse_iterator<iterator> reverse_iterator;
	/**
	\brief A type that provides a random-access iterator that can read any <code>const</code> element in the vector.
	*/
	typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

	/**
	\brief Calls the default constructor for every element
	*/
	object();

	/**
	\brief Construct an uninitialized vector

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

	template<
		typename ...Args
	>
	explicit
	object(
		Args const &...
	);

	/**
	\brief Copy-construct the vector from another vector
	*/
	object(
		object const &
	);

	/**
	\brief Create a vector from a vector with the same dimension and value
	type but different storage type

	\tparam OtherStorage The other vector's storage type
	*/
	template<
		typename OtherStorage
	>
	explicit
	object(
		fcppt::math::vector::object<
			T,
			N,
			OtherStorage
		> const &
	);

	FCPPT_MATH_DETAIL_ARRAY_ADAPTER(
		object
	)

	/**
	\brief Copy the values from a different vector
	*/
	object &
	operator=(
		object const &
	);

	/**
	\brief Copy the values from a different vector
	\tparam OtherStorage The other vector's storage type
	*/
	template<
		typename OtherStorage
	>
	object &
	operator=(
		fcppt::math::vector::object<
			T,
			N,
			OtherStorage
		> const &
	);

	~object();

#define FCPPT_MATH_VECTOR_OBJECT_DECLARE_OPERATOR(op)\
FCPPT_MATH_DETAIL_MAKE_OP_DECL(\
	template<\
		typename OtherStorage\
	>, \
	(object<T, N, OtherStorage>),\
	3,\
	op \
)

	FCPPT_MATH_VECTOR_OBJECT_DECLARE_OPERATOR(+=)
	FCPPT_MATH_VECTOR_OBJECT_DECLARE_OPERATOR(-=)
	FCPPT_MATH_VECTOR_OBJECT_DECLARE_OPERATOR(*=)
	FCPPT_MATH_VECTOR_OBJECT_DECLARE_OPERATOR(/=)
	FCPPT_MATH_VECTOR_OBJECT_DECLARE_OPERATOR(%=)
#undef FCPPT_MATH_VECTOR_OBJECT_DECLARE_OPERATOR

	/**
	\brief Multiply a vector by a scalar
	*/
	object &
	operator*=(
		value_type const &
	);

	/**
	\brief Divide a vector by a scalar
	*/
	object &
	operator/=(
		value_type const &
	);

	/**
	\brief Returns a reference to the vector element at a specified position.

	\warning
	Behaviour is undefined if the index is out of range.
	*/
	const_reference
	operator[](
		size_type
	) const;

	/**
	\brief Returns a reference to the vector element at a specified position.

	\warning
	Behaviour is undefined if the index is out of range.
	*/
	reference
	operator[](
		size_type
	);

	/**
	\brief Returns the vector filled with all zeroes
	*/
	static
	fcppt::math::vector::object<
		T,
		N,
		fcppt::math::static_storage<
			T,
			N
		>
	> const
	null();

	/**
	\brief Returns a reference to the first element in the vector
	*/
	reference
	x();

	/**
	\brief Returns a reference to the first element in the vector
	*/
	const_reference
	x() const;

	/**
	\brief Returns a reference to the second element in the vector

	\warning
	This will fail at compile-time if <code>N <= 1</code>
	*/
	reference
	y();

	/**
	\brief Returns a reference to the second element in the vector

	\warning
	This will fail at compile-time if <code>N <= 1</code>
	*/
	const_reference
	y() const;

	/**
	\brief Returns a reference to the third element in the vector

	\warning
	This will fail at compile-time if <code>N <= 2</code>
	*/
	reference
	z();

	/**
	\brief Returns a reference to the third element in the vector

	\warning
	This will fail at compile-time if <code>N <= 2</code>
	*/
	const_reference
	z() const;

	/**
	\brief Returns a reference to the fourth element in the vector

	\warning
	This will fail at compile-time if <code>N <= 3</code>
	*/
	reference
	w();

	/**
	\brief Returns a reference to the fourth element in the vector

	\warning
	This will fail at compile-time if <code>N <= 3</code>
	*/
	const_reference
	w() const;

	/**
	\brief Exchanges the elements of two vectors.
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
\brief Exchanges the elements of two vectors.
*/
template<
	typename T,
	typename N,
	typename S
>
void
swap(
	fcppt::math::vector::object<
		T,
		N,
		S
	> &,
	fcppt::math::vector::object<
		T,
		N,
		S
	> &
);

}
}
}

#endif
