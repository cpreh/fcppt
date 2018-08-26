//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_OPTIONAL_OBJECT_DECL_HPP_INCLUDED

#include <fcppt/optional/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace optional
{

/**
\brief A class that makes values optional

\ingroup fcpptoptional

\tparam T The type to make optional, which must be CopyConstructible or
Movable, Assignable or AssignMovable and complete. It therefore must also not
be const.

See the \link fcpptoptional module description \endlink for more information.
*/
template<
	typename T
>
class object
{
public:
	static_assert(
		!std::is_const<
			T
		>::value,
		"optionals cannot hold const types"
	);

	static_assert(
		!std::is_reference<
			T
		>::value,
		"optionals cannot hold reference types"
	);

	/**
	\brief The value type
	*/
	typedef
	T
	value_type;

	/**
	\brief The non const reference type to <code>value_type</code>
	*/
	typedef
	T
	&reference;

	/**
	\brief The const reference type to <code>value_type</code>
	*/
	typedef
	T const &
	const_reference;

	/**
	\brief Constructs an empty optional

	\post has_value() will be false.
	*/
	object();

	/**
	\brief Constructs an optional from a const_reference

	Constructs an optional by copying from \a ref.

	\param ref The value to initialize the optional with

	\post <code>has_value()</code> will be true.
	*/
	explicit
	object(
		const_reference ref
	);

	/**
	\brief Constructs an optional by moving from an rvalue reference

	Constructs an optional by moving from \a ref

	\param ref The value to move from

	\post <code>has_value()</code> will be true
	*/
	explicit
	object(
		T &&ref
	);

	/**
	\brief Copy constructs an optional

	Constructs an optional by copying from \a other if
	<code>other.has_value()</code> is true. Otherwise, the new optional
	will have no value.

	\param other The optional to copy from
	*/
	object(
		object const &other
	);

	/**
	\brief Move constructs an optional

	Constructs an optional by moving from \a other. In any case, \a other
	will be left uninitialized.

	\param other The optional to move from
	*/
	object(
		object &&other
	)
	noexcept(
		std::is_nothrow_move_constructible<
			T
		>::value
	);

	/**
	\brief Assigns from an optional

	Assigns the current value from <code>*other</code> if
	<code>has_value()</code> and <code>other.has_value()</code> are true.
	Otherwise, if <code>has_value()</code> is false, then the current value
	will be copy constructed from <code>*other</code>. Otherwise, if
	<code>other.has_value()</code> is false, then the optional will be
	reset.

	\param other The optional to assign from

	\return <code>*this</code>
	*/
	object &
	operator=(
		object const &other
	);

	/**
	\brief Move assigns from an optional

	Moves the current value from <code>*other</code>
	if <code>has_value()</code> and <code>other.has_value()</code> are true.
	Otherwise, if <code>has_value()</code> is false, then the current value
	will be move constructed from <code>*other</code>. Otherwise, if
	<code>other.has_value()</code> is false, then the optional will be
	reset.

	\param other The optional to move assign from

	\return <code>*this</code>
	*/
	object &
	operator=(
		object &&other
	)
	noexcept(
		std::is_nothrow_move_constructible<
			T
		>::value
		&&
		std::is_nothrow_move_assignable<
			T
		>::value
	);

	/**
	\brief Destroys the value, if any

	If <code>has_value()</code> is true then the current value will be
	destroyed
	*/
	~object();

	/**
	\brief Returns a reference to the current value

	\warning The behaviour is undefined if <code>has_value()</code> is false
	*/
	reference
	get_unsafe();

	/**
	\brief Returns a const reference to the current value

	\warning The behaviour is undefined if <code>has_value()</code> is false
	*/
	const_reference
	get_unsafe() const;

	/**
	\brief Returns whether the optional holds a value
	*/
	bool
	has_value() const;
private:
	typedef T *pointer;

	typedef T const *const_pointer;

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
		fcppt::optional::object<
			Other
		> const &
	);

	void
	move_from(
		T &&
	);

	void
	move_from(
		object &&
	);

	void
	reset();

	object &
	assign(
		const_reference
	);

	template<
		typename Other
	>
	object &
	assign(
		fcppt::optional::object<
			Other
		> const &
	);

	object &
	move_assign(
		T &&
	);

	object &
	move_assign(
		object &&
	);

	void
	destroy();

	typedef
	std::aligned_storage_t<
		sizeof(
			T
		),
		std::alignment_of<
			T
		>::value
	>
	storage_type;

	storage_type storage_;

	bool initialized_;
};

}
}

#endif
