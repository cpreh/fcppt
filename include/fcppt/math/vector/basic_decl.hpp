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

\section Motivation

The need for a vector class representing n-dimensional points or arrows arises
very quickly in many disciplines. The simplest approach to this problem is to
use a plain old array (or, slightly better, an fcppt::container::array) to
represent those values:

\code
fcppt::container::array<float,3> point = {{1.0f,2.0f,3.0f}};
\endcode

This approach, however, isn't very comfortable. To add two vectors, you need a
separate function (let's call it <code>add</code>):

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

But you shouldn't overload operators for fcppt::container::array. To work
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
private:
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
adequate.

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
private:
	Storage storage_;
};
\endcode

You might wonder why I didn't just use <code>Storage</code> as the only
template parameter. This has practical reasons; the dimension and the value
type shouldn't depend on the storage type (fcppt::math::vector::basic does it
like this, too). Since the dimension for dynamic vectors isn't known, but the
vector above <em>still</em> has a dimension type, we need to reserve some
special type to denote "doesn't have a compile-time dimension" for the
<code>N</code> parameter. But that's just implementation trouble, we won't
concern ourselves with it. For static vectors, we set
<code>N = boost::mpl::integral_c<M></code> where <code>M</code> is a number.

This looks more complicated, but it turns out that this is advantageous in
another way: with some modifications, we can now define a vector type that
doesn't actually hold it's data in its own array, but is just pointing to a
location in memory (think about setting <code>Storage = float*</code>). This is
what's typically called a <em>view</em> and it's very powerful. The matrix
class, for example, holds its contents in a two-dimensional array. Taking a
column or row from the matrix should ideally return a vector. This is now
possible, since vector can access an arbitrary memory location to get and set
its values.

\section PODness and variadic constructors

As you have seen in the motivation section, you can initialize an array with a
neat initializer syntax:

\code
fcppt::container::array<int,3> a = {{1,2,3}};
\endcode

This is possible because fcppt::container::array is a "POD" type (see <a href="http://www.boost.org/doc/libs/1_40_0/libs/type_traits/doc/html/boost_typetraits/reference/is_pod.html">here</a>
for an explanation). fcppt::math::vector::basic is not a POD type, so you
cannot initialize it that way. However, since comfortable initialization is
very important for readable code, we added pseudo-variadic constructors to the
vector class.
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
