//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_DECL_HPP_INCLUDED
#define FCPPT_OPTIONAL_DECL_HPP_INCLUDED

#include <fcppt/optional_fwd.hpp>
#include <fcppt/detail/enable_optional_ref_conv.hpp>
#include <fcppt/detail/enable_optional_value_conv.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief A class that makes values optional
\ingroup fcpptoptional
\tparam T The type to make optional, which must be CopyConstructible,
Assignable and complete. It therefore must also not be const.

See the \link fcpptoptional module description \endlink for more information.
*/
template<
	typename T
>
class optional
{
public:
	static_assert(
		!std::is_const<
			T
		>::value,
		"optionals can't hold const types"
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
		fcppt::optional<
			Other
		> const &other,
		typename fcppt::detail::enable_optional_value_conv<
			T,
			Other,
			void
		>::type const * = nullptr
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
	typename fcppt::detail::enable_optional_value_conv<
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

	/**
	\brief Explicit boolean test

	\return <code>this->has_value()</code>
	*/
	explicit
	operator
	bool() const;
private:
	pointer
	data();

	const_pointer
	data() const;

	void *
	raw_data();
	
	void const *
	raw_data() const;

	void
	construct(
		const_reference
	);

	template<
		typename Other
	>
	void
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

	void
	destroy();

	void
	destroy_unchecked();

	typedef typename std::aligned_storage<
		sizeof(T),
		std::alignment_of<
			T
		>::value
	>::type storage_type;

	storage_type storage_;

	bool initialized_;
};

/**
\brief A specialization for optional references

\ingroup fcpptoptional

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
public:
	/**
	\brief The value type of the optional reference

	The value type of the optional reference is always non const.
	*/
	typedef typename std::remove_const<
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
		>::type * = nullptr
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
	\brief Returns a pointer to the current reference

	\return If<code>has_value()</code> is true, returns the a pointer to
	the current reference, otherwise return 0.
	*/
	pointer
	data() const;

	/**
	\brief Returns whether the optional holds a reference
	*/
	bool
	has_value() const;

	/**
	\brief Explicit boolean test

	\return <code>this->has_value()</code>
	*/
	explicit
	operator
	bool() const;
private:
	pointer data_;
};

}

#endif
