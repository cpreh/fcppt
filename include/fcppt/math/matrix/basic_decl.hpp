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

<table id="toc">
<tr>
<td>

<ol>
	<li>\ref fcpptmathmatrixbasic_motivation</li>
	<li>\ref fcpptmathmatrixbasic_operators</li>
	<li>\ref fcpptmathmatrixbasic_accessing_elements</li>
	<li>\ref fcpptmathmatrixbasic_identity_and_null</li>
	<li>\ref fcpptmathmatrixbasic_iteration</li>
</ol>

</td>
</tr>
</table>

\section fcpptmathmatrixbasic_motivation Motivation

Matrices are ubiqituous in mathematics and computer science. Often, matrices
represent linear operations and are applied to accordingly-sized vectors. Since
fcppt already provides a vector class, there's the need for a complementary
matrix class and operations.

The meaning of fcppt::math::matrix::basic's template parameters is the same as
for vector and dim, so it'll not be explained in detail here. We will only
touch the differences between a vector and a matrix, so you should read the
documentation for fcppt::math::vector::basic before reading this introduction.

Of course, a matrix has two dimension parameters instead of one. Again, we have
the metafunctions \link fcppt::math::matrix::static_ static_ \endlink and \link
fcppt::math::matrix::dynamic dynamic \endlink to typedef static and dynamic
matrices, respectively.

A matrix can be constructed using a variadic constructor which takes the matrix
components in row-major order. This way, you can arrange the matrix's
components nicely in the source code, as seen in the following example:

\code
typedef
fcppt::math::matrix::static_
<
	int,
	2,
	3
>::type
int_matrix_3x3;

int_matrix_3x3 m(
	1,2,3,
	4,5,6);

// Will print: ((1,2,3),(4,5,6))
std::cout << m;
\endcode

To cast between matrices of different value and storage types, you have
fcppt::math::matrix::structure_cast. There are, however, no functions to
"expand" or "narrow" a matrix. You have to do that yourself.

\section fcpptmathmatrixbasic_accessing_elements Accessing elements

The <code>operator[]</code> in C++ only takes one argument. This is fine for
one-dimensional data structures like an array (or a vector). For
multi-dimensional structures, you have to work around it, for example:

<ol>
	<li>
		Use a function instead of an operator to access the elements.
		Functions can, of course, take two arguments:
		<code>matrix.at(x,y) = 10;</code>
	</li>
	<li>
		Use <code>operator()</code> (the function call operator)
		instead of the array access operator: <code>matrix(x,y) =
		10;</code>
	</li>
	<li>
		Nest two <code>operator[]</code> expressions:
		<code>matrix[x][y] = 10;</code>.
	</li>
</ol>

fcppt chose to implement the latter. In the statement
<code>matrix[x][y]</code>, matrix::basic's <code>operator[]</code> is invoked and
returns a <em>proxy vector</em> representing the x-th row in the matrix. You
can then do all the things you could do with a normal vector (for example, take
the dot product, add it to another vector and so on).

\note
This functionality is not (yet) available to access the y-th <em>row</em> of a
matrix. You'd have to transpose the matrix and then take the y-th row do
achieve that.

\section fcpptmathmatrixbasic_grid Grid

The astute documentation reader might have noticed that there already is a
multi-dimensional data structure included in fcppt:
fcppt::container::grid::object. This is not an accident. The grid class is, by
definition, n-dimensional and dynamic in size. Also, it is able to hold
arbitrary (copyable) elements, not just numbers. Defining mathematical
operators on it doesn't make any sense. Conversely, some operations like linear
interpolation don't make any sense in the context of a matrix. So defining two
classes for these different use cases is well-justified (until we are proven
wrong by a cleverly written hybrid class!).

There are subtle differences and similarities between the classes:

<ul>
	<li>
		Both matrix::basic and grid, store their data in linear
		(one-dimensional) form and calculate the linear index from the
		n-dimensional tuple.
	</li>
	<li>
		Accessing individual elements from a vector is done with a
		proxy vector class for matrices (see above), the grid wants a
		<code>dim</code> to denote positions.
	</li>
	<li>
		The grid doesn't define any mathematical operators.
	</li>
	<li>
		The grid doesn't have a storage type.
	</li>
</ul>

\section fcpptmathmatrixbasic_operators Operators

Including <strong><code>fcppt/math/matrix/basic_decl.hpp</code></strong> you
will get the following operators (<code>S2</code> defines some other storage
type):

<ul>
	<li><code>operator+=(matrix::basic<T,M,N,S2>)</code></li>
	<li><code>operator-=(matrix::basic<T,M,N,S2>)</code></li>
	<li><code>operator*=(T)</code> (multiply by a scalar)</li>
	<li><code>operator/=(T)</code> (divide by a scalar)</li>
	<li><code>operator=(matrix::basic const &)</code> (regular assignment operator)</li>
	<li><code>operator=(dim::basic<T,M,N,S2> const &)</code></li>
	<li><code>operator[](size_type)</code> (see above)</li>
</ul>

The arithmetic operators all work component-wise.

Including <strong><code>fcppt/math/matrix/comparison.hpp</code></strong> you
get all the comparison operators:

<ul>
	<li><code>operator==</code></li>
	<li><code>operator!=</code></li>
</ul>

All of these work component-wise and forward to the <code>value_type</code>'s
operators. Keep in mind that the equality comparison operators do <em>not</em>
use an epsilon so you <em>will</em> get exact floating point comparisons (be
sure that you really want that!).

Including <strong><code>fcppt/math/matrix/arithmetic.hpp</code></strong> gives
you the following operators:

<ul>
	<li><code>operator+(matrix::matrix<T,M,N,S1>,matrix::basic<T,M,N,S2>)</code></li>
	<li><code>operator-(matrix::matrix<T,M,N,S1>,matrix::basic<T,M,N,S2>)</code></li>
	<li><code>operator*(matrix::basic<T,M,N,S>,matrix::basic<T,N,M2,S>)</code> (matrix multiplication - will return a <code>matrix::basic<T,M1,M2,?></code> where <code>?</code> is determined by fcppt::math::matrix::normal_storage.)</li>
	<li><code>operator*(matrix::basic<T,M,N,S>,T)</code> (scalar multiplication)</li>
	<li><code>operator/(matrix::basic<T,M,N,S>,T)</code> (scalar division)</li>
</ul>

<code>operator+</code> and <code>operator-</code> work component-wise. The
matrix multiplication operator currently uses no sophisticated multiplication
technique, just the regular text-book matrix multiplication.

Including <strong><code>fcppt/math/matrix/output.hpp</code></strong> gives you
an <code>operator<<</code>.

Including <strong><code>fcppt/math/matrix/vector.hpp</code></strong> gives you:

<pre>
vector::basic<T,M,S2>
operator*(
	matrix::basic<T,N,M,S1> const &,
	vector::basic<T,N,S2> const &);
</pre>

\section fcpptmathmatrixbasic_identity_and_null Identity and null

To get the identity matrix, use the static <code>identity</code> function:

\code
typedef
fcppt::math::matrix::static_<int,3,3>::type
int_matrix_3x3;

int_matrix_3x3 m = int_matrix_3x3::identity();
\endcode

Mutatis mutandis with <code>null</code>:

\code
typedef
fcppt::math::matrix::static_<int,3,3>::type
int_matrix_3x3;

int_matrix_3x3 m = int_matrix_3x3::null();
\endcode

\section fcpptmathmatrixbasic_iteration Iteration

To iterate over all elements in the matrix, use an iterator together with begin/end:

\code
typedef
fcppt::math::matrix::static_<int,3,3>::type
int_matrix_3x3;

int_matrix_3x3 m = int_matrix_3x3::identity();

// Will output: 1,0,0,0,1,0,0,0,1,
for(int_matrix_3x3::const_iterator it = m.begin(); it != m.end(); ++it)
	std::cout << *it << ",";
\endcode

This code might puzzle you. Didn't I just say that matrix's
<code>operator[]</code> returns a proxy vector representing one row of the
matrix? Indeed, I did.

When it comes to iteration, however, we do <em>not</em> use proxy vectors, but
regular pointers to the individual matrix cells. If you want to iterate over
all rows, use a loop using an index instead of an iterator:

\code
typedef
fcppt::math::matrix::static_<int,3,3>::type
int_matrix_3x3;

int_matrix_3x3 m = int_matrix_3x3::identity();

// Will output: (1,0,0),(0,1,0),(0,0,1),
for(int_matrix_3x3::size_type row = 0; row < m.rows(); ++it)
	std::cout << m[row] << ",";
\endcode
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
