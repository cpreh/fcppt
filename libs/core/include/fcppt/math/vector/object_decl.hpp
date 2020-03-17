//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_OBJECT_DECL_HPP_INCLUDED

#include <fcppt/no_init_fwd.hpp>
#include <fcppt/math/difference_type.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/static_size.hpp>
#include <fcppt/math/vector/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
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

\tparam N The vector's dimension

\tparam S The vector's storage type

\ingroup fcpptmathvector

See \ref fcpptmathvector for more information.
*/
template<
	typename T,
	fcppt::math::size_type N,
	typename S
>
class object
{
public:
	/**
	\brief A typedef for the \p N parameter
	*/
	using
	dim_wrapper
	=
	fcppt::math::static_size<
		N
	>;

	/**
	\brief The static size
	*/
	using
	static_size
	=
	dim_wrapper;

	/**
	\brief A typedef for the \p S parameter
	*/
	using
	storage_type
	=
	S;

	/**
	\brief A type that counts the number of elements in a vector.
	*/
	using
	size_type
	=
	fcppt::math::size_type;

	/**
	\brief A type that provides the difference between the addresses of two
	elements in a vector.
	*/
	using
	difference_type
	=
	fcppt::math::difference_type;

	/**
	\brief A type that represents the data type stored in a vector.
	*/
	using
	value_type
	=
	T;

	/**
	\brief A type that provides a reference to an element stored in a
	vector.
	*/
	using
	reference
	=
	typename
	storage_type::reference;

	/**
	\brief A type that provides a reference to a <code>const</code> element
	stored in a vector for reading and performing <code>const</code>
	operations.
	*/
	using
	const_reference
	=
	typename
	storage_type::const_reference;

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
	*/
	explicit
	object(
		storage_type &&
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
	\brief Move-construct the vector from another vector
	*/
	object(
		object &&
	)
	noexcept(
		// NOLINTNEXTLINE(hicpp-noexcept-move,performance-noexcept-move-constructor)
		std::is_nothrow_move_constructible_v<
			storage_type
		>
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

	/**
	\brief Copy the values from a different vector
	*/
	object &
	operator=(
		object const &
	);

	/**
	\brief Move the values from a different vector
	*/
	object &
	operator=(
		object &&
	)
	noexcept(
		// NOLINTNEXTLINE(hicpp-noexcept-move,performance-noexcept-move-constructor)
		std::is_nothrow_move_assignable_v<
			storage_type
		>
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

	/**
	\brief Add a vector.
	*/
	template<
		typename S2
	>
	object &
	operator+=(
		object<
			T,
			N,
			S2
		> const &
	);

	/**
	\brief Subtract a vector.
	*/
	template<
		typename S2
	>
	object &
	operator-=(
		object<
			T,
			N,
			S2
		> const &
	);

	/**
	\brief Multiply by a vector.
	*/
	template<
		typename S2
	>
	object &
	operator*=(
		object<
			T,
			N,
			S2
		> const &
	);

	/**
	\brief Multiply a vector by a scalar.
	*/
	object &
	operator*=(
		value_type const &
	);

	/**
	\brief Returns a reference to the vector element at a specified position.

	\warning
	Behaviour is undefined if the index is out of range.
	*/
	[[nodiscard]]
	const_reference
	get_unsafe(
		size_type
	) const;

	/**
	\brief Returns a reference to the vector element at a specified position.

	\warning
	Behaviour is undefined if the index is out of range.
	*/
	[[nodiscard]]
	reference
	get_unsafe(
		size_type
	);

	/**
	\brief Returns a reference to the first element in the vector
	*/
	[[nodiscard]]
	reference
	x();

	/**
	\brief Returns a reference to the first element in the vector
	*/
	[[nodiscard]]
	const_reference
	x() const;

	/**
	\brief Returns a reference to the second element in the vector
	*/
	[[nodiscard]]
	reference
	y();

	/**
	\brief Returns a reference to the second element in the vector
	*/
	[[nodiscard]]
	const_reference
	y() const;

	/**
	\brief Returns a reference to the third element in the vector
	*/
	[[nodiscard]]
	reference
	z();

	/**
	\brief Returns a reference to the third element in the vector
	*/
	[[nodiscard]]
	const_reference
	z() const;

	/**
	\brief Returns a reference to the fourth element in the vector
	*/
	[[nodiscard]]
	reference
	w();

	/**
	\brief Returns a reference to the fourth element in the vector
	*/
	[[nodiscard]]
	const_reference
	w() const;

	[[nodiscard]]
	S &
	storage();

	[[nodiscard]]
	S const &
	storage() const;
private:
	S storage_;
};

}
}
}

#endif
