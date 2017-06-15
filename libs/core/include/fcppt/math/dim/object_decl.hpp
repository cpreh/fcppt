//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DIM_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_MATH_DIM_OBJECT_DECL_HPP_INCLUDED

#include <fcppt/no_init_fwd.hpp>
#include <fcppt/math/difference_type.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/static_size.hpp>
#include <fcppt/math/detail/make_op_decl.hpp>
#include <fcppt/math/dim/object_fwd.hpp>


namespace fcppt
{
namespace math
{
namespace dim
{

/**
\brief A class representing a static n-dimensional dimension
\tparam T The dim's <code>value_type</code>
\tparam N The dim's dimension type (this is not necessarily a number!)
\tparam S The dim's storage type
\ingroup fcpptmathdim

See the \link fcpptmathdim module description \endlink for more information.
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
	typedef
	fcppt::math::static_size<
		N
	>
	dim_wrapper;

	typedef
	dim_wrapper
	static_size;

	/**
	\brief A typedef for the \p S parameter
	*/
	typedef
	S
	storage_type;

	/**
	\brief A type that counts the number of elements in a dim.
	*/
	typedef
	fcppt::math::size_type
	size_type;

	/**
	\brief A type that provides the difference between the addresses of two elements in a dim.
	*/
	typedef
	fcppt::math::difference_type
	difference_type;

	/**
	\brief A type that represents the data type stored in a dim.
	*/
	typedef
	T
	value_type;

	/**
	\brief A type that provides a reference to an element stored in a dim.
	*/
	typedef
	typename
	storage_type::reference
	reference;

	/**
	\brief A type that provides a reference to a <code>const</code> element stored in a dim for reading and performing <code>const</code> operations.
	*/
	typedef
	typename
	storage_type::const_reference
	const_reference;

	/**
	\brief Construct an uninitialized dim

	\warning
	The content of the dim will be undefined (not null) after
	initialization
	*/
	explicit
	object(
		fcppt::no_init const &
	);

	/**
	\brief Construct a dim from a storage source
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
	\brief Copy-construct the dim from another dim
	*/
	object(
		object const &
	);

	/**
	\brief Create a dim from a dim with the same dimension and value type but different storage type
	\tparam OtherStorage The other dim's storage type
	*/
	template<
		typename OtherStorage
	>
	explicit
	object(
		fcppt::math::dim::object<
			T,
			N,
			OtherStorage
		> const &
	);

	/**
	\brief Copy the values from a different dim
	*/
	object &
	operator=(
		object const &
	);

	/**
	\brief Copy the values from a different dim
	\tparam OtherStorage The other dim's storage type
	*/
	template<
		typename OtherStorage
	>
	object &
	operator=(
		fcppt::math::dim::object<
			T,
			N,
			OtherStorage
		> const &
	);

	~object();

#define FCPPT_MATH_DIM_OBJECT_DECLARE_OPERATOR(op)\
FCPPT_MATH_DETAIL_MAKE_OP_DECL(\
	template<\
		typename OtherStorage\
	>, \
	(object<T, N, OtherStorage>),\
	3,\
	op \
)

	FCPPT_MATH_DIM_OBJECT_DECLARE_OPERATOR(+=)
	FCPPT_MATH_DIM_OBJECT_DECLARE_OPERATOR(-=)
	FCPPT_MATH_DIM_OBJECT_DECLARE_OPERATOR(*=)
	FCPPT_MATH_DIM_OBJECT_DECLARE_OPERATOR(/=)
	FCPPT_MATH_DIM_OBJECT_DECLARE_OPERATOR(%=)
#undef FCPPT_MATH_DIM_OBJECT_DECLARE_OPERATOR

	/**
	\brief Multiply a dim by a scalar
	*/
	object &
	operator*=(
		value_type const &
	);

	/**
	\brief Divide a dim by a scalar
	*/
	object &
	operator/=(
		value_type const &
	);

	/**
	\brief Returns a reference to the dim element at a specified position.

	\warning
	Behaviour is undefined if the index is out of range.
	*/
	reference
	operator[](
		size_type
	);

	/**
	\brief Returns a reference to the dim element at a specified position.

	\warning
	Behaviour is undefined if the index is out of range.
	*/
	const_reference
	operator[](
		size_type
	) const;

	/**
	\brief Returns a reference to the first element in the dim
	*/
	reference
	w();
	/**
	\brief Returns a reference to the first element in the dim
	*/
	const_reference
	w() const;
	/**
	\brief Returns a reference to the second element in the dim

	\warning
	This will fail at compile-time if <code>N <= 1</code>
	*/
	reference
	h();
	/**
	\brief Returns a reference to the second element in the dim

	\warning
	This will fail at compile-time if <code>N <= 1</code>
	*/
	const_reference
	h() const;
	/**
	\brief Returns a reference to the third element in the dim

	\warning
	This will fail at compile-time if <code>N <= 2</code>
	*/
	reference
	d();
	/**
	\brief Returns a reference to the third element in the dim

	\warning
	This will fail at compile-time if <code>N <= 2</code>
	*/
	const_reference
	d() const;

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

