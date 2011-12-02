//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DIM_BASIC_DECL_HPP_INCLUDED
#define FCPPT_MATH_DIM_BASIC_DECL_HPP_INCLUDED

#include <fcppt/math/difference_type.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/array_adapter.hpp>
#include <fcppt/math/detail/make_op_decl.hpp>
#include <fcppt/math/detail/make_variadic_constructor_decl.hpp>
#include <fcppt/math/dim/basic_fwd.hpp>
#include <fcppt/math/dim/max_ctor_params.hpp>
#include <fcppt/type_traits/is_iterator.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <iterator>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace dim
{

/**
\brief A class representing dynamic or static n-dimensional dimensions
\tparam T The dim's <code>value_type</code>
\tparam N The dim's dimension type (this is not necessarily a number!)
\tparam S The dim's storage type
\ingroup fcpptmathdim

<table id="toc">
<tr>
<td>

<ol>
	<li>\ref fcpptmathdimbasic_motivation</li>
	<li>\ref fcpptmathdimbasic_converting_from_and_to_vectors</li>
	<li>\ref fcpptmathdimbasic_headers</li>
</ol>

</td>
</tr>
</table>

\section fcpptmathdimbasic_motivation Motivation

When writing code that deals with geometry, you need a type to denote the
size (or extent) of the geometry for each dimension. You also need such a class
when writing multi-dimensional containers (like
fcppt::container::grid::object).

Conceptually, you could just use fcppt::math::vector::basic, and we (the
authors of fcppt) have thought about going that way. However, a vector just
isn't a dimension type. You have operations you can apply to a vector (like the
dot product) that make no sense in the context of a dimension. Conversely, you
have operations like "take the area of the dimension" that make no sense for
vectors. Also, the lower-dimensional getters for vector (meaning
<code>x(),y(),z(),w()</code>) are not mixed with the lower-dimensional getters
for dim (meaning <code>w(),h(),d()</code>).

So don't be confused, vector and dim are distinct types, not (strong) typedefs
of another. They have a very similar interface (and the same template
parameters), but not the same member and free functions.

\section fcpptmathdimbasic_converting_from_and_to_vectors Converting from and to vectors

To convert a dimension to a vector, use fcppt::math::dim::structure_cast:

\code
typedef
fcppt::math::dim::static_<int,3>::type
dim3;

typedef
fcppt::math::vector::static_<int,3>::type
vector3;

dim3 d(1,2,3);

vector3 v = fcppt::math::dim::structure_cast<vector3>(d);
\endcode

Conversely, use fcppt::math::vector::structure_cast to convert a vector to a dim:

\code
typedef
fcppt::math::dim::static_<int,3>::type
dim3;

typedef
fcppt::math::vector::static_<int,3>::type
vector3;

vector3 d(1,2,3);

dim3 v = fcppt::math::vector::structure_cast<dim3>(d);
\endcode

If you include the fcppt/math/vector/dim.hpp header, you get the operators
<code>+-*%/</code> which all have the signature

<pre>
vector::basic<T,N,S> operator(vector::basic<T,N,S> left,dim::basic<T,N,S>)
</pre>

This way, you can add a dimension to a vector, for example.

\section fcpptmathdimbasic_headers Header files

fcppt::math::dim is spread out across various header files. There's one
header per free function. fcppt::math::dim::basic itself is split into
various headers, too. Here's an exhaustive list:

<table>
<tr>
<th>Header file</th>
<th>Description</th>
</tr>
<tr>
<td><code>basic_fwd.hpp</code></td>
<td>Contains \link fcppt::math::dim::basic basic's \endlink declaration. Include this if you pass a dim by reference, for example.</td>
</tr>
<tr>
<td><code>basic_decl.hpp</code></td>
<td>Contains \link fcppt::math::dim::basic basic's \endlink definition.</td>
</tr>
<tr>
<td><code>basic_impl.hpp</code></td>
<td>Contains the definition of \link fcppt::math::dim::basic basic's \endlink member functions.</td>
</tr>
<tr>
<td><code>basic.hpp</code></td>
<td>Includes <code>basic_fwd.hpp</code>, <code>basic_decl.hpp</code> and <code>basic_impl.hpp</code></td>
</tr>
<tr>
<td><code>arithmetic.hpp</code></td>
<td>Contains \link fcppt::math::dim::basic basic's \endlink arithmetic operators.</td>
</tr>
<tr>
<td><code>comparison.hpp</code></td>
<td>Contains \link fcppt::math::dim::basic basic's \endlink comparison operators.</td>
</tr>
<tr>
<td><code>input.hpp</code></td>
<td>Contains an <code>operator>></code> for the standard input streams (wide and narrow) which expects dims to be input in the format: <code>(v1,v2,v3,...)</code></td>
</tr>
<tr>
<td><code>output.hpp</code></td>
<td>Contains an <code>operator<<</code> for the standard input streams (wide and narrow) which outputs dims in the format: <code>(v1,v2,v3,...)</code></td>
</tr>
</table>
*/
template<
	typename T,
	typename N,
	typename S
>
class basic
{
public:
	/**
	\brief A typedef for the \p N parameter
	*/
	typedef N dim_wrapper;
	/**
	\brief A typedef for the \p S parameter
	*/
	typedef S storage_type;

	/**
	\brief A type that counts the number of elements in a dim.
	*/
	typedef math::size_type size_type;
	/**
	\brief A type that provides the difference between the addresses of two elements in a dim.
	*/
	typedef math::difference_type difference_type;
	/**
	\brief A type that represents the data type stored in a dim.
	*/
	typedef T value_type;
	/**
	\brief A type that provides a reference to an element stored in a dim.
	*/
	typedef value_type &reference;
	/**
	\brief A type that provides a reference to a <code>const</code> element stored in a dim for reading and performing <code>const</code> operations.
	*/
	typedef value_type const &const_reference;
	/**
	\brief A type that provides a pointer to an element in a dim.
	*/
	typedef T *pointer;
	/**
	\brief A type that provides a pointer to a <code>const</code> element in a dim.
	*/
	typedef T const *const_pointer;
	/**
	\brief A type that provides a random-access iterator that can read or modify any element in a dim.
	*/
	typedef pointer iterator;
	/**
	\brief A type that provides a random-access iterator that can read a <code>const</code> element in a dim.
	*/
	typedef const_pointer const_iterator;
	/**
	\brief A type that provides a random-access iterator that can read or modify any element in a reversed dim.
	*/
	typedef std::reverse_iterator<iterator> reverse_iterator;
	/**
	\brief A type that provides a random-access iterator that can read any <code>const</code> element in the dim.
	*/
	typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

	/**
	\brief Construct an uninitialized dim

	\warning
	The content of the dim will be undefined (not null) after
	initialization
	*/
	basic();

	/**
	\brief Construct a dim from a storage source
	\param s The storage source to copy from
	*/
	explicit basic(
		storage_type const &s
	);

	/**
	\brief Copy-construct the dim from another dim
	*/
	basic(
		basic const &
	);

	/**
	\brief Create a dim from a dim with the same dimension and value type but different storage type
	\tparam OtherStorage The other dim's storage type
	*/
	template<
		typename OtherStorage
	>
	basic(
		basic<
			T,
			N,
			OtherStorage
		> const &
	);

	/**
	\brief Create a dim and fill it with the contents of the given range
	\tparam In a forward iterator pointing to elements of type <code>T</code>
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

	FCPPT_MATH_DETAIL_ARRAY_ADAPTER(basic)

	FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR_DECL(
		FCPPT_MATH_DIM_MAX_CTOR_PARAMS,
		basic
	)

	/**
	\brief Copy the values from a different dim
	\tparam OtherStorage The other dim's storage type
	*/
	basic &
	operator=(
		basic const &
	);

	/**
	\brief Copy the values from a different dim
	*/
	template<
		typename OtherStorage
	>
	basic &
	operator=(
		basic<
			T,
			N,
			OtherStorage
		> const &
	);

	/**
	\brief Destroy the dim
	*/
	~basic();

#define FCPPT_MATH_DIM_BASIC_DECLARE_OPERATOR(op)\
FCPPT_MATH_DETAIL_MAKE_OP_DECL(\
	template<\
		typename OtherStorage\
	>, \
	(basic<T, N, OtherStorage>),\
	3,\
	op \
)

	FCPPT_MATH_DIM_BASIC_DECLARE_OPERATOR(+=)
	FCPPT_MATH_DIM_BASIC_DECLARE_OPERATOR(-=)
	FCPPT_MATH_DIM_BASIC_DECLARE_OPERATOR(*=)
	FCPPT_MATH_DIM_BASIC_DECLARE_OPERATOR(/=)
	FCPPT_MATH_DIM_BASIC_DECLARE_OPERATOR(%=)
#undef FCPPT_MATH_DIM_BASIC_DECLARE_OPERATOR

	/**
	\brief Multiply a dim by a scalar
	*/
	basic &
	operator*=(
		value_type const &
	);

	/**
	\brief Divide a dim by a scalar
	*/
	basic &
	operator/=(
		value_type const &
	);

	/**
	\brief Returns a reference to the dim element at a specified position.
	*/
	reference
	operator[](
		size_type
	);

	/**
	\brief Returns a reference to the dim element at a specified position.
	*/
	const_reference
	operator[](
		size_type
	) const;

	/**
	\brief Returns the pointer to the store.

	May return 0 if the dim is empty.
	*/
	pointer
	data();

	/**
	\brief Returns the pointer to the store.

	May return 0 if the dim is empty.
	*/
	const_pointer
	data() const;

	/**
	\brief Returns the number of elements in the dim.
	*/
	size_type
	size() const;

	/**
	\brief Returns a reference to the first element in the dim
	*/
	reference w();
	/**
	\brief Returns a reference to the first element in the dim
	*/
	const_reference w() const;
	/**
	\brief Returns a reference to the second element in the dim

	\warning
	This will fail at compile-time if <code>N <= 1</code>
	*/
	reference h();
	/**
	\brief Returns a reference to the second element in the dim

	\warning
	This will fail at compile-time if <code>N <= 1</code>
	*/
	const_reference h() const;
	/**
	\brief Returns a reference to the third element in the dim

	\warning
	This will fail at compile-time if <code>N <= 2</code>
	*/
	reference d();
	/**
	\brief Returns a reference to the third element in the dim

	\warning
	This will fail at compile-time if <code>N <= 2</code>
	*/
	const_reference d() const;

	/**
	\brief Returns the area/volume of the dimension

	This is equal to the product of all components of the dimension.
	*/
	value_type
	content() const;

	/**
	\brief Returns the dim filled with all zeroes
	*/
	static basic const
	null();

	/**
	\brief Exchanges the elements of two dims.
	*/
	void
	swap(
		basic &
	);
private:
	S storage_;
};

/**
\brief Exchanges the elements of two dims.
*/
template<
	typename T,
	typename N,
	typename S
>
void
swap(
	basic<T, N, S> &,
	basic<T, N, S> &
);

}
}
}

#endif

