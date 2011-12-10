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
*/
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

	typedef math::size_type size_type;
	typedef math::difference_type difference_type;

	typedef T value_type;

	typedef vector::basic<
		T,
		N,
		matrix::detail::row_view<
			T,
			N
		>
	> reference;

	typedef vector::basic<
		T,
		N,
		matrix::detail::row_view<
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
	S storage_;
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
