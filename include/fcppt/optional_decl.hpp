//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_DECL_HPP_INCLUDED
#define FCPPT_OPTIONAL_DECL_HPP_INCLUDED

#include <fcppt/optional_fwd.hpp>
#include <fcppt/safe_bool.hpp>
#include <fcppt/alignment/array.hpp>
#include <fcppt/detail/enable_optional_ref_conv.hpp>
#include <fcppt/detail/enable_optional_value_conv.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/alignment_of.hpp>
#include <boost/type_traits/is_const.hpp>
#include <boost/type_traits/remove_const.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief A class that makes values optional

\ingroup fcpptmain

\tparam T The type to make optional, which must be CopyConstructible,
Assignable and complete. It therefore must also not be const.

<table id="toc">
<tr>
<td>

<ol>
	<li>\ref optional_motivation</li>
	<li>\ref optional_value</li>
	<li>\ref optional_reference</li>
	<li>\ref optional_design</li>
	<li>\ref optional_headers</li>
</ol>

</td>
</tr>
</table>

\section optional_motivation Motivation

Sometimes it is necessary to distinguish between having a value and having
none.
There are several ways that are often used to make this work:
<ul>
<li>Using a <em>special value</em> which indicates no value, for example
<code>static_cast<unsigned>(-1)</code></li>
<li>Using a pointer to a value and set the pointer to NULL to indicate no
value</li>
<li>Setting an additional bool flag</li>
</ul>

All of these have several shortcomings:
<ul>
<li>Special values might not be available, and on top of that they are very
error prone.</li>
<li>Pointers to temporaries that might vanish cannot be passed around. For
example a function returning a value cannot do so by a pointer.</li>
<li>Additional bool flags are cumbersome to handle and are error
prone as well.</li>
</ul>

An fcppt::optional instead is a wrapper around a value that can be absent.
Here is a small example.
\code
typedef fcppt::optional<
	unsigned
> optional_uint;

void
test_function(
	optional_uint opt
)
{
	// Test if opt is set
	if(
		opt.has_value()
	)
		// Output the value
		// This is undefined if has_value() == false
		std::cout << *opt << '\n';
}

// Prints nothing
test_function(
	optional_uint()
);

// Prints 3
test_function(
	optional_uint(3u)
);
\endcode

\section optional_value Values

If fcppt::optional<T> is used and T is not a reference type, the optional will
be an optional value. An optional value, as its name suggests, has value
semantics, meaning that it will copy the value. Therefore, T has to be
CopyConstructible and Assignable with the usual meanings. Here is a small
example:

\code
typedef fcppt::optional<
	unsigned
> optional_uint;

unsigned int1(5u);

// opt takes a copy of int1
optional_uint opt(int1);

int1 = 10u;

// The value of opt will still be 5u
assert(
	*opt != int1
);
\endcode

Optional values, denoted by fcppt::optional<T>, have some special semantics,
in contrast to optional references:
<ul>
<li>They can be assigned from an expression of type T const &.</li>
<li>They can be constructed from an fcppt::optional<T &> or an
fcppt::optional<T const &>. This has the same semantics as constructing a T
from a T & or T const & with the addition that has_value will be preserved.</li>
<li>They can also be assigned from an fcppt::optional<T &> or an
fcppt::optional<T const &> with the same semantics.</li>
<li>An optional value can be reset, using fcppt::optional<T>::reset. The
optional will have no value after that.</li>
<li>Their own constness determines if they can be modified which means if the
stored value is const and if the optional can be reset or assigned a new
value.</li>
</ul>

For optional references, see \ref optional_reference

\section optional_design Design

There is already <code>%boost::optional</code> so you might wonder why
fcppt provides its own optional type. It is actually quite similar to
<code>%boost::optional</code> in the sense that it stores optional values
by value and not by means of dynamically allocated memmory. This means
that an optional value is at least as big as its type it holds.
The key differences to <code>%boost::optional</code> are
<ul>
<li>fcppt::optional<T> uses alignment support from the compiler instead of
relying on the hacky <code>%boost::detail::aligned_storage</code></li>
<li>fcppt::optional doesn't have an implicit constructor.</li>
<li>fcppt::optional<T &> doesn't allow implicit conversions for assignment</li>
</ul>

\section optional_headers Header files

fcppt::optional is spread out across various header files.

<table>
<tr>
<th>Header file</th>
<th>Description</th>
</tr>
<tr>
<td><code>optional_fwd.hpp</code></td>
<td>Contains \link fcppt::optional optional's \endlink declaration.</td>
</tr>
<tr>
<td><code>optional_decl.hpp</code></td>
<td>Contains \link fcppt::optional optional's \endlink definition.</td>
</tr>
<tr>
<td><code>optional_impl.hpp</code></td>
<td>Contains the definition of \link fcppt::optional optional's \endlink member functions.</td>
</tr>
<tr>
<td><code>optional_comparison.hpp</code></td>
<td>Contains operator== and operator!=</td>
</tr>
</table>
*/
template<
	typename T
>
class optional
{
	FCPPT_SAFE_BOOL(
		optional
	)
public:
	BOOST_STATIC_ASSERT(
		!boost::is_const<
			T
		>::value
	);

	/**
	\brief The value type
	*/
	typedef T value_type;

	/**
	\brief The non const reference type to <code>value_type</code>
	*/
	typedef T &reference;

	/**
	\brief The const reference type to <code>value_type</code>
	*/
	typedef T const &const_reference;

	/**
	\brief The non const pointer type to <code>value_type</code>
	*/
	typedef T *pointer;

	/**
	\brief The const pointer type to <code>value_type</code>
	*/
	typedef T const *const_pointer;

	/**
	\brief Constructs an empty optional

	\post has_value() will be false.
	*/
	optional();

	/**
	\brief Constructs an optional from a const_reference

	Constructs an optional by copying from \a ref.

	\param ref The value to initialize the optional with

	\post has_value() will be true.
	*/
	explicit
	optional(
		const_reference ref
	);

	/**
	\brief Constructs an optional from an optional to a reference

	Construct an optional by copying from \a other if
	<code>other.has_value()</code> is true. Otherwise, the new optional
	will have no value. This is a special constructor to make constructing
	an optional value from an optional reference possible.

	\param other The optional to copy from
	*/
	template<
		typename Other
	>
	explicit
	optional(
		optional<
			Other
		> const &other,
		typename detail::enable_optional_value_conv<
			T,
			Other,
			void
		>::type const * = 0
	);

	/**
	\brief Copy constructs an optional

	Constructs an optional by copying from \a other if
	<code>other.has_value()</code> is true. Otherwise, the new optional
	will have no value.

	\param other The optional to copy from
	*/
	optional(
		optional const &other
	);

	/**
	\brief Assigns from an optional

	Assigns the current value from <code>*other</code> if
	<code>has_value()</code> and <code>other.has_value()</code> are true.
	Otherwise, if has_value() is false, then the current value will be copy
	constructed from <code>*other</code>. Otherwise, if
	<code>other.has_value()</code> is false, then the optional will be
	reset.

	\param other The optional to assign from

	\return <code>*this</code>
	*/
	optional &
	operator=(
		optional const &other
	);

	/**
	\brief Assigns from a const reference

	Assign the current value from <code>other</code> if
	<code>has_value()</code> is true. Otherwise, the current value will be
	copy constructed from <code>other</code>.

	\param other The const reference to assign from

	\post has_value() will be true.

	\return <code>*this</code>
	*/
	optional &
	operator=(
		const_reference other
	);

	/**
	\brief Assigns from an optional reference

	This is a special assignment operator to make assignment from optional
	references possible. It is otherwise identical to the normal assignment
	operator.

	\see fcppt::optional::operator=(optional const &)
	*/
	template<
		typename Other
	>
	typename detail::enable_optional_value_conv<
		T,
		Other,
		optional &
	>::type
	operator=(
		optional<
			Other
		> const &
	);

	/**
	\brief Destroys the value, if any

	If <code>has_value()</code> is true then the current value will be
	destroyed
	*/
	~optional();

	/**
	\brief Returns a reference to the current value

	\warning The behaviour is undefined if <code>has_value()</code> is false
	*/
	reference
	operator*();

	/**
	\brief Returns a const reference to the current value

	\warning The behaviour is undefined if <code>has_value()</code> is false
	*/
	const_reference
	operator*() const;

	/**
	\brief Returns the pointer to the current value

	\warning The behaviour is undefined if <code>has_value()</code> is false
	*/
	pointer
	operator->();

	/**
	\brief Returns the const pointer to the current value

	\warning The behaviour is undefined if <code>has_value()</code> is false
	*/
	const_pointer
	operator->() const;

	/**
	\brief Resets the optional and destroys its value, if any

	If <code>has_value()</code> is true, then the current value will be
	destroyed.

	\post <code>has_value() will be false</code>
	*/
	void
	reset();

	/**
	\brief Returns whether the optional holds a value
	*/
	bool
	has_value() const;
private:
	bool
	boolean_test() const;

	pointer
	construct(
		const_reference
	);

	template<
		typename Other
	>
	pointer
	construct(
		optional<
			Other
		> const &
	);

	optional &
	assign(
		const_reference
	);

	template<
		typename Other
	>
	optional &
	assign(
		optional<
			Other
		> const &
	);

	template<
		typename Other
	>
	void
	copy_from_other(
		Other const &
	);

	void
	destroy();

	typedef typename alignment::array<
		unsigned char,
		sizeof(T),
		boost::alignment_of<
			T
		>::value
	>::type storage_type;

	storage_type storage_;

	pointer data_;
};

/**
\brief A specialization for optional references

\ingroup fcpptmain

\tparam T The reference type to make optional, which doesn't have to be
CopyConstructible, Assignable or even complete.

\section optional_reference Optional references

Optional references are somewhat similar to pointers. However, pointers are a
much broader concept: In addition to making references optional (by using the
null pointer), they can be used to manage dynamically allocated memory using
new and delete or other allocation and deallocation functions, or they can be
used to address static or dynamic arrays using pointer arithmetic. Therefore,
pointers are too broad a concept. fcppt::optional<T &> only focuses on one
thing: Making a reference optional. As a benefit, it also default-initializes
to the empty optional, where an uninitialized pointer would be undefined.

See \ref optional_motivation for a general explanation of optionals and \ref
optional_value for optional values.

If fcppt::optional<T> is used and T is a reference type (either T = U & or T =
U const &), the optional will be an optional reference. An optional reference
holds its value by reference and has therefore no ownership over it. Here is a
small example:

\code
typedef fcppt::optional<
	unsigned &
> optional_uint;

unsigned int1(5u);

// opt takes int1 by reference
optional_uint opt(int1);

int1 = 10u;

// The value of opt will also be 10u
assert(
	*opt == int1
);
\endcode

Optional references, denoted by fcppt::optional<T &> or fcppt::optional<T const
&>, have some special semantics, in contrast to optional values:
<ul>
<li>They cannot be assigned from expressions of type T & or T const &. Assign
a new optional instead: <code>my_value = optional_ref(other_ref)</code></li>
<li>They cannot be reset. Assign an empty optional instead.</li>
<li>It is possible to construct an fcppt::optional<T const &> from an
fcppt::optional<T &>.</li>
</ul>

*/
template<
	typename T
>
class optional<
	T &
>
{
	FCPPT_SAFE_BOOL(
		optional
	)
public:
	/**
	\brief The value type of the optional reference

	The value type of the optional reference is always non const.
	*/
	typedef typename boost::remove_const<
		T
	>::type value_type;

	/**
	\brief The reference type

	The reference type the optional reference holds. If this is a const
	reference or not depends on the template parameter
	*/
	typedef T &reference;

	/**
	\brief The pointer type

	The pointer type corresponding to the reference type the optional
	reference holds. If this is const or not depends on the template
	parameter.
	*/
	typedef T *pointer;

	/**
	\brief Constructs an empty optional

	\post <code>has_value()</code> will be false
	*/
	optional();

	/**
	\brief Constructs an optional reference from a reference

	Stores \a ref inside the optional. This will not copy anything.

	\param ref The reference to store in the optional

	\post <code>has_value()</code> will be true
	*/
	explicit
	optional(
		reference ref
	);

	/**
	\brief Constructs an fcppt::optional<T const &> from an
	fcppt::optional<T &>

	Constructs an optional reference by taking the reference from \a other
	if <code>other.has_value()</code> is true. Otherwise, the new optional
	will have no value. This is a special constructor to allow conversion
	between an <code>fcppt::optional<T &></code> to <code>fcppt::optional<T
	const &></code>

	\param other The optional to copy from
	*/
	template<
		typename Other
	>
	explicit optional(
		optional<
			Other &
		> const &other,
		typename detail::enable_optional_ref_conv<
			T,
			Other
		>::type * = 0
	);

	/**
	\brief Copy constructs an optional reference

	Constructs an optional by taking the reference from \a other if
	<code>other.has_value()</code> is true. Otherwise, the new optional
	will have no value.
	*/
	optional(
		optional const &other
	);

	/**
	\brief Assigns from an optional reference

	Assigns the reference from \a other if <code>other.has_value()</code>
	is true. Otherwise, the optional reference will have no value.
	*/
	optional &
	operator=(
		optional const &
	);

	~optional();

	/**
	\brief Returns the current reference

	\warning The behaviour is undefined if <code>has_value()</code> is false
	*/
	reference
	operator*() const;

	/**
	\brief Returns the current reference by pointer

	\warning The behaviour is undefined if <code>has_value()</code> is false
	*/
	pointer
	operator->() const;

	/**
	\brief Returns whether the optional holds a reference
	*/
	bool
	has_value() const;
private:
	bool
	boolean_test() const;

	pointer data_;
};

}

#endif
