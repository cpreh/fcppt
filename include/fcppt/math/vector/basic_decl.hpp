//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_BASIC_DECL_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_BASIC_DECL_HPP_INCLUDED

#include <fcppt/math/difference_type.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/array_adapter.hpp>
#include <fcppt/math/detail/make_op_decl.hpp>
#include <fcppt/math/detail/make_variadic_constructor_decl.hpp>
#include <fcppt/math/vector/basic_fwd.hpp>
#include <fcppt/math/vector/max_ctor_params.hpp>
#include <fcppt/type_traits/is_iterator.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <iterator>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace vector
{

/**
\brief A class representing dynamic or static n-dimensional vectors
\tparam T The vector's <code>value_type</code>
\tparam N The vector's dimension type (this is not necessarily a number!)
\tparam S The vector's storage type
\ingroup fcpptmathvector

<table id="toc">
<tr>
<td>

<ol>
	<li>\ref fcpptmathvector_motivation</li>
	<li>\ref fcpptmathvector_declaring_vectors</li>
	<li>\ref fcpptmathvector_podness_and_variadic_constructors</li>
	<li>\ref fcpptmathvector_type_safety_and_dimension_conversion</li>
	<li>\ref fcpptmathvector_null_vectors_and_comparisons</li>
	<li>\ref fcpptmathvector_headers</li>
</ol>

</td>
</tr>
</table>

\section fcpptmathvector_motivation Motivation

The need for a vector class representing n-dimensional points or arrows arises
very quickly in many disciplines. The simplest approach to this problem is to
use a plain old array (or, slightly better, an fcppt::container::array) to
represent those values:

\code
fcppt::container::array<float,3> point = {{1.0f,2.0f,3.0f}};
\endcode

As you can see, we can initialize the structure very elegantly with the struct member
initialization syntax. This approach is, however, not very comfortable. To add
two vectors, you need a separate function (let's call it <code>add</code>):

\code
template<typename T,std::size_t N>
fcppt::container::array<T,N>
add(
	fcppt::container::array<T,N> const &left,
	fcppt::container::array<T,N> const &right)
{
	fcppt::container::array<T,N> result;
	for(std::size_t i = 0; i < N; ++i)
		result[i] = left[i] + right[i];
	return result;
}

int main()
{
	fcppt::container::array<float,3>
		point1 = {{1.0f,2.0f,3.0f}},
		point2 = {{4.0f,5.0f,6.0f}};

	fcppt::container::array<float,3> result =
		add(
			point1,
			point2);
}
\endcode

This is kind of awkward. Operator overloading would be much more suited for
this job (in this case, of course, we would overload <code>operator+</code>).

But you shouldn't overload operators for fcppt::container::array, other people
using the class might not want to have your <code>operator+</code>. To work
around that, we need a small wrapper around the array:

\code
template<typename T,std::size_t N>
class vector
{
public:
	// We need to access the the individual components
	T &operator[](std::size_t const i)
	{
		return storage_[i];
	}

	T &operator[](std::size_t const i)
	{
		return storage_[i];
	}

	vector
	operator+(
		vector const &other) const
	{
		vector result;
		for(std::size_t i = 0; i < N; ++i)
			result[i] = left[i] + right[i];
		return result;
	}

	// Has to be public to keep the type a POD type (read on for more
	// information)
	fcppt::container::array<T,N> storage_;
};

int main()
{
	vector<float,3>
		point1 = {{1.0f,2.0f,3.0f}},
		point2 = {{4.0f,5.0f,6.0f}};

	fcppt::container::array<float,3> result =
		point1 + point2;
}
\endcode

Much better! Now we can define the other operators like <code>+*-/</code>, too,
and operations like computing the dot or cross product. However, there are a
few things that still bug us. For example, the vector's size is fixed at
compile time.  What if we have a program that needs dynamically sized vectors?

\code
int main()
{
	std::size_t N;
	std::cout << "Please enter the vector dimensions: ";
	std::cin >> N;

	std::cout << "Please enter the vector components: ";
	// Oh dear
	vector<float,N> a;
	for(std::size_t i = 0; i < N; ++i)
		cin >> result[i];
}
\endcode

The code above will fail, of course. You cannot instantiate a template at
run-time. In this case, a dynamic array like a <code>std::%vector</code> is more
adequate. But we want to keep our operators and operations (like the dot
product), just with a different container as "backend".

Simply replacing the fcppt::container::array by a <code>std::%vector</code>
might be short-sighted, though. The code will be exactly the same, but the
performance won't be. Since <code>std::%vector</code> <em>always</em> uses
<code>new</code> and <code>delete</code>, this might cost you quite a bit of
performance in situations where the size <em>is</em> known at compile time.
Using a fcppt::container::raw_vector doesn't help, either, since that won't
kill the <code>new</code>/<code>delete</code>.

To be as flexible as possible, you have no choice but to make the underlying
storage a template parameter:

\code
template<typename T,typename N,typename Storage>
class vector
{
public:
	// We need to access the the individual components
	T &operator[](std::size_t const i)
	{
		return storage_[i];
	}

	T &operator[](std::size_t const i)
	{
		return storage_[i];
	}

	vector
	operator+(
		vector const &other) const
	{
		vector result;
		for(std::size_t i = 0; i < N; ++i)
			result[i] = left[i] + right[i];
		return result;
	}

	Storage storage_;
};
\endcode

I made just a few changes, but they're subtle and we need to analyze the code
carefully.

Firstly, you might wonder why I didn't just use <code>Storage</code> as the only
template parameter. You could use <code>Storage::value_type</code> to retrieve
<code>T</code> and <code>Storage::static_size</code> to retrieve N (only if
<code>Storage</code> is an fcppt::container::array, of course). Using three
template parameters has practical reasons; the dimension and the value
type shouldn't depend on the storage type (fcppt::math::vector::basic does it
like this, too).

Secondly, we now have a generic type for the dimension (<code>typename N</code>
vs. <code>std::size_t N</code>). That's because the dimension template
parameter doesn't make sense for dynamic vectors. In this case, we reserve a
special type to denote "doesn't have a compile time dimension. For static
vectors, we set <code>N = boost::mpl::integral_c<M></code> where <code>M</code>
is a number.

This looks more complicated, but it turns out that this is advantageous in
another way: with some modifications, we can now define a vector type that
doesn't actually hold it's data in its own array, but is just pointing to a
location in memory (think about setting <code>Storage = float*</code>). This is
what's typically called a <em>view</em> and it's very powerful. The matrix
class, for example, holds its contents in a two-dimensional array. Taking a
column or row from the matrix should ideally return a vector. This is now
possible, since vector can access an arbitrary memory location to get and set
its values.

\section fcpptmathvector_declaring_vectors Declaring vectors

fcppt::math::vector::basic is declared like this:

\code
template<typename T,typename N,typename S>
class vector;
\endcode

To typedef a <em>static</em> vector, you can write:

\code
typedef
fcppt::math::vector::basic
<
	float,
	boost::mpl::integral_c<fcppt::math::size_type,2>,
	fcppt::container::array<float,2>
>
vector2f;
\endcode

As you can see, this is error-prone and verbose. If you want to change the
vector's data type or dimension, you have change it in two places.

Luckily, there is a better way to do it:

\code
typedef
fcppt::math::vector::static_<float,2>::type
vector2f;
\endcode

This looks a bit cleaner and it's the best we can do with pure C++03 (C++11 has
ways to make it better).

\note
In case you're wondering, we cannot name this type <code>static</code> because
that's a keyword.

\warning
Don't forget the <code>::%type</code> at the end of the <code>static_<></code>.
You will get strange error messages because fcppt::math::vector::static_
actually is a class you can instantiate. But you're not supposed to do that.

With <em>dynamic</em> vectors, it's almost the same. You can write...

\code
typedef
fcppt::math::vector::basic
<
	float,
	fcppt::math::detail::dynamic_size,
	fcppt::container::raw_vector<float>
>
vectorf;
\endcode

...or you can write:

\code
typedef
fcppt::math::vector::dynamic<float>::type
vectorf;
\endcode

\section fcpptmathvector_podness_and_variadic_constructors PODness and variadic constructors

As you have seen in the motivation section, you can initialize an array with a
neat initializer syntax:

\code
fcppt::container::array<int,3> a = {{1,2,3}};
\endcode

This is possible because fcppt::container::array is a "POD" type (see <a href="http://www.boost.org/doc/libs/1_40_0/libs/type_traits/doc/html/boost_typetraits/reference/is_pod.html">here</a>
for an explanation). fcppt::math::vector::basic is not a POD type, so you
cannot initialize it that way. However, since comfortable initialization is
very important for readable code, we added "pseudo-variadic" constructors to
the vector class. It looks like this:

\code
int main()
{
	typedef
	fcppt::math::vector::static_<float,2>::type
	vector2f;

	// Compiles and runs just fine
	vector2f v1(1.0f,2.0f);

	// Leaves the vector uninitialized (will _not_ set it to (0,0)!)
	vector2f v2;

	// This is wrong and won't compile, too few arguments.
	// vector2f v3(1.0f);

	// Also wrong, too many arguments.
	// vector2f v4(1.0f,2.0f,3.0f);
}
\endcode

This also works with dynamic vectors:

\code
int main()
{
	typedef
	fcppt::math::vector::dynamic<float>::type
	vectorf;

	// Vectors with zero length are allowed
	vectorf v1;
	vectorf v2(1.0f);
	vectorf v3(1.0f,2.0f);
	vectorf v4(1.0f,2.0f,3.0f);
	// and so forth
}
\endcode

Since variadic templates are a C++11 feature and fcppt is a C++03 library, we
emulate the variadic constructors using the preprocessor. This means that there
is an upper limit for the generation of the constructors. To view or change the
limit, look inside:

<code>fcppt/math/vector/max_ctor_params.hpp</code>

\section fcpptmathvector_type_safety_and_dimension_conversion Type safety and dimension conversion

In some areas, fcppt::math::vector::basic behaves like numeric type it
encapsulates. It has most of the numeric operators, can be freely copied and so
on. Conversion between vectors, however, are always explicit. The following code will compile just fine:

\code
int main()
{
	int i = 10;
	float f = i;
}
\endcode

The following code, however, will not compile:

\code
int main()
{
	fcppt::math::vector::static_<int,1>::type i(10);
	fcppt::math::vector::static_<float,1>::type f = i;
}
\endcode

If you want to make it work, use fcppt::math::vector::structure_cast, as such:

\code
int main()
{
	fcppt::math::vector::static_<int,1>::type i(10);
	fcppt::math::vector::static_<float,1>::type f =
		fcppt::math::vector::structure_cast
		<
			fcppt::math::vector::static_<float,1>
		>(
			i);
}
\endcode

The same logic applies to vectors of different dimensions. The following will fail:

\code
int main()
{
	fcppt::math::vector::static_<int,1>::type small(10);
	// Convert smaller to bigger
	fcppt::math::vector::static_<int,2>::type bigger(small);
	// Convert bigger to smaller
	fcppt::math::vector::static_<int,1>::type small_again(bigger);
}
\endcode

To make this work, use fcppt::math::vector::construct and fcppt::math::vector::narrow_cast:

\code
int main()
{
	fcppt::math::vector::static_<int,1> small(10);
	// Convert smaller to bigger. Only works for N and N+1 and we have to
	// specify the additional coordinate.
	fcppt::math::vector::static_<int,2> bigger(
		fcppt::math::vector::construct(
			small,
			20));
	// Convert bigger to smaller
	fcppt::math::vector::static_<int,1> small_again(
		fcppt::math::vector::narrow_cast
		<
			fcppt::math::vector::static_<int,1>
		>(
			bigger));
}
\endcode

\section fcpptmathvector_null_vectors_and_comparisons Null vectors and comparisons

To get a vector with all zeroes, use the static member function <code>::%null()</code>:

\code
int main()
{
	typedef
	fcppt::math::vector::static_<float,2>::type
	vector2f;

	vector2f n = vector2f::null();
}
\endcode

To compare two vectors, you <em>can</em> use the comparison operators:

\code
int main()
{
	typedef
	fcppt::math::vector::static_<float,2>::type
	vector2f;

	vector2f x(1.0f,2.0f),y(1.0f,2.0f);

	std::cout << (x == y) << "," << (x - y == vector2f::null()) << "\n";
}
\endcode

This will use the float comparison operator. However, since floating point
values are inherently inaccurate, an exact comparison is almost <em>never</em>
what you want to do. Instead, you should use a different method for comparsion.
For example, you could check if the Euclidean distance is small enough, using
fcppt::math::vector::length:

\code
int main()
{
	typedef
	fcppt::math::vector::static_<float,2>::type
	vector2f;

	vector2f x(1.0f,2.0f),y(1.0f,2.0f);
	float const epsilon = 0.001f;

	std::cout << (fcppt::math::vector::length(x - y) < epsilon) << "\n";
}
\endcode

Or, you could test if one of the components exceeds the given epsilon, using
fcppt::math::range_compare:

\code
int main()
{
	typedef
	fcppt::math::vector::static_<float,2>::type
	vector2f;

	vector2f x(1.0f,2.0f),y(1.0f,2.0f);
	float const epsilon = 0.001f;

	std::cout << fcppt::math::range_compare(x,y,epsilon) << "\n";
}
\endcode

\section fcpptmathvector_headers Header files

fcppt::math::vector is spread out across various header files. There's one
header per free function. fcppt::math::vector::basic itself is split into
various headers, too. Here's an exhaustive list:

<table>
<tr>
<th>Header file</th>
<th>Description</th>
</tr>
<tr>
<td><code>basic_fwd.hpp</code></td>
<td>Contains \link fcppt::math::vector::basic basic's \endlink forward declaration. Include this if you pass a vector by reference, for example.</td>
</tr>
<tr>
<td><code>basic_decl.hpp</code></td>
<td>Contains \link fcppt::math::vector::basic basic's \endlink declaration.</td>
</tr>
<tr>
<td><code>basic_impl.hpp</code></td>
<td>Contains \link fcppt::math::vector::basic basic's \endlink implementation.</td>
</tr>
<tr>
<td><code>basic.hpp</code></td>
<td>Includes <code>basic_fwd.hpp</code>, <code>basic_decl.hpp</code> and <code>basic_impl.hpp</code></td>
</tr>
<tr>
<td><code>arithmetic.hpp</code></td>
<td>Contains \link fcppt::math::vector::basic basic's \endlink arithmetic operators.</td>
</tr>
<tr>
<td><code>comparison.hpp</code></td>
<td>Contains \link fcppt::math::vector::basic basic's \endlink comparison operators.</td>
</tr>
<tr>
<td><code>input.hpp</code></td>
<td>Contains an <code>operator>></code> for the standard input streams (wide and narrow) which expects vectors to be input in the format: <code>(v1,v2,v3,...)</code></td>
</tr>
<tr>
<td><code>output.hpp</code></td>
<td>Contains an <code>operator<<</code> for the standard input streams (wide and narrow) which outputs vectors in the format: <code>(v1,v2,v3,...)</code></td>
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
	typedef N dim_wrapper;

	typedef S storage_type;

	typedef math::size_type size_type;
	typedef math::difference_type difference_type;
	typedef T value_type;
	typedef value_type &reference;
	typedef value_type const &const_reference;
	typedef T *pointer;
	typedef T const *const_pointer;
	typedef pointer iterator;
	typedef const_pointer const_iterator;
	typedef std::reverse_iterator<iterator> reverse_iterator;
	typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

	basic();

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

	FCPPT_MATH_DETAIL_ARRAY_ADAPTER(
		basic
	)

	FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR_DECL(
		FCPPT_MATH_VECTOR_MAX_CTOR_PARAMS,
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
			OtherStorage
		> const &
	);

	~basic();

/// \cond FCPPT_DOXYGEN_DEBUG
#define FCPPT_MATH_VECTOR_BASIC_DECLARE_OPERATOR(op)\
FCPPT_MATH_DETAIL_MAKE_OP_DECL(\
	template<\
		typename OtherStorage\
	>, \
	(basic<T, N, OtherStorage>),\
	3,\
	op \
)
/// \endcond

	FCPPT_MATH_VECTOR_BASIC_DECLARE_OPERATOR(+=)
	FCPPT_MATH_VECTOR_BASIC_DECLARE_OPERATOR(-=)
	FCPPT_MATH_VECTOR_BASIC_DECLARE_OPERATOR(*=)
	FCPPT_MATH_VECTOR_BASIC_DECLARE_OPERATOR(/=)
	FCPPT_MATH_VECTOR_BASIC_DECLARE_OPERATOR(%=)
#undef FCPPT_MATH_VECTOR_BASIC_DECLARE_OPERATOR

	basic &
	operator*=(
		value_type const &
	);

	basic &
	operator/=(
		value_type const &
	);

	const_reference
	operator[](
		size_type
	) const;

	reference
	operator[](
		size_type
	);

	pointer
	data();

	const_pointer
	data() const;

	size_type
	size() const;

	static basic const
	null();

	reference
	x();

	const_reference
	x() const;

	reference
	y();

	const_reference
	y() const;

	reference
	z();

	const_reference
	z() const;

	reference
	w();

	const_reference
	w() const;

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
