// Copyright 2009 Howard Hinnant, Ion Gazta&ntilde;aga.
// Copyright 2010-2012 Carl Philipp Reh
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
// See http://www.boost.org/libs/foreach for documentation


#ifndef FCPPT_UNIQUE_PTR_DECL_HPP_INCLUDED
#define FCPPT_UNIQUE_PTR_DECL_HPP_INCLUDED

#include <fcppt/safe_bool.hpp>
#include <fcppt/unique_ptr_fwd.hpp>
#include <fcppt/detail/rvalue_ref_fwd.hpp>
#include <fcppt/preprocessor/disable_icc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/type_traits/add_reference.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_ICC_WARNING(2289)
FCPPT_PP_DISABLE_ICC_WARNING(2304)

/**
\brief A unique pointer class, designed to emulate <em>C++11's</em>
<code>std::unique_ptr</code>

\ingroup fcpptsmartptr

A unique pointer is similar to <code>std::auto_ptr</code> (which is deprecated
in C++11), because only one object holds ownership over a pointer. The
difference is that unique_ptr disallows certain things that auto_ptr allowed
(like moving from lvalue).

\tparam Type The type the unique pointer points to

\tparam Deleter A deleter class that must be callable with a pointer to Type.
*/
template<
	typename Type,
	typename Deleter
>
class unique_ptr
{
	FCPPT_SAFE_BOOL(
		unique_ptr
	)
private:
	unique_ptr(
		unique_ptr &
	);

	unique_ptr &
	operator=(
		unique_ptr &
	);
public:
	/**
	\brief The element type, which is \a Type
	*/
	typedef Type element_type;

	/**
	\brief Same as element_type
	*/
	typedef element_type value_type;

	/**
	\brief The reference type
	*/
	typedef typename boost::add_reference<
		element_type
	>::type reference;

	/**
	\brief The pointer type, same as <code>value_type *</code>
	*/
	typedef element_type *pointer;

	/**
	\brief Used for marking rvalues

	This implicit conversion operator will convert a unique ptr into a
	marked rvalue.
	*/
	operator fcppt::detail::rvalue_ref<
		unique_ptr
	>();

	/**
	\brief Construction from a marked rvalue
	*/
	unique_ptr(
		fcppt::detail::rvalue_ref<
			unique_ptr
		>
	);

	/**
	\brief Assignment from a marked rvalue
	*/
	unique_ptr &
	operator=(
		fcppt::detail::rvalue_ref<
			unique_ptr
		>
	);

	/**
	\brief Constructs an empty unique_ptr

	get() will return a null pointer
	*/
	unique_ptr();

	/**
	\brief Constructs a unique_ptr from a pointer

	Constructs the unique_ptr from \a ptr, taking ownership of it.

	\param ptr The pointer to take ownership of
	*/
	explicit
	unique_ptr(
		pointer ptr
	);

	/**
	\brief Moves from a compatible unique_ptr

	Moves from \a other, taking ownerhsip of its pointer. If \a other is
	empty, then this unique_ptr will also be empty.

	\tparam Other A type, so that <code>Other *</code> is implicitly
	convertible to <code>Type *</code>

	\param other The unique_ptr to move from
	*/
	template<
		typename Other
	>
	unique_ptr(
		fcppt::unique_ptr<
			Other,
			Deleter
		> other
	);

	/**
	\brief Destroys the unique_ptr

	If the unique_ptr is empty, nothing happens. Otherwise, the owned
	object will be destroyed, which will be done by Deleter().
	*/
	~unique_ptr();

	/**
	\brief Assigns a unique_ptr from a compatible unique_ptr

	If this unique_ptr is not empty, then the owned object will be
	destroyed. Afterwards, \a other will move the ownership to this
	unique_ptr.

	\tparam Other A type, so that <code>Other *</code> is implicitly
	convertible to <code>Type *</code>

	\param other The unique_ptr to assign from
	*/
	template<
		typename Other
	>
	unique_ptr &
	operator=(
		fcppt::unique_ptr<
			Other,
			Deleter
		> other
	);

	/**
	\brief Dereferences the owned pointer

	Returns a reference to the owned object.

	\warning The behaviour is undefined if the unique_ptr is empty.
	*/
	reference
	operator*() const;

	/**
	\brief Dereferences a member of the owned object

	Returns a pointer to the owned object.

	\warning The behaviour is undefined if the unique_ptr is empty.
	*/
	pointer
	operator->() const;

	/**
	\brief Returns a pointer to the owned object

	Returns a pointer to the owned object or the null pointer if the
	unique_ptr is empty.
	*/
	pointer
	get() const;

	/**
	\brief Resets this unique_ptr

	If this unique_ptr is empty, nothing happens. Otherwise, the owned
	object will be destroyed. In any case, this unique_ptr will be empty.
	*/
	void
	reset();

	/**
	\brief Resets this unique_ptr from a pointer

	If this unique_ptr is empty, no destruction happens. Otherwise, the
	previously owned object will be destroyed. After that, this unique_ptr
	will take ownership of \a other.

	\param other The pointer to take ownership of
	*/
	void
	reset(
		pointer other
	);

	/**
	\brief Releases the ownership

	Returns the currently owned pointer, and makes this unique_ptr empty,
	effectively releasing ownership.
	*/
	pointer
	release();

	/**
	\brief Swaps the unique_ptr

	Swaps the unique_ptr with \a other.

	\param other The unique_ptr to swap with
	*/
	void
	swap(
		unique_ptr &other
	);
private:
	bool
	boolean_test() const;

	void
	destroy();

	pointer ptr_;

};
// \cond
FCPPT_PP_POP_WARNING
// \endcond

/**
\brief Swaps two unique pointers

\ingroup fcpptsmartptr

Swaps \a left and \a right

\param left The left argument

\param right The right argument
*/
template<
	typename Type,
	typename Deleter
>
void
swap(
	fcppt::unique_ptr<
		Type,
		Deleter
	> &left,
	fcppt::unique_ptr<
		Type,
		Deleter
	> &right
);

/**
\brief Compares two unique ptrs for equality

\ingroup fcpptsmartptr

Compares \a left and \a right for equality, comparing their pointers. Pointers
to \a Type1 and to \a Type2 must be equality comparable.

\param left The left argument

\param right The right argument
*/
template<
	typename Type1,
	typename Type2,
	typename Deleter
>
bool
operator==(
	fcppt::unique_ptr<
		Type1,
		Deleter
	> const &left,
	fcppt::unique_ptr<
		Type2,
		Deleter
	> const &right
);

/**
\brief Compares two unique ptrs for inequality

\ingroup fcpptsmartptr

Compares \a left and \a right for inequality, comparing their pointers.
Pointers to \a Type1 and to \a Type2 must be inequality comparable.

\param left The left argument

\param right The right argument
*/
template<
	typename Type1,
	typename Type2,
	typename Deleter
>
bool
operator!=(
	fcppt::unique_ptr<
		Type1,
		Deleter
	> const &left,
	fcppt::unique_ptr<
		Type2,
		Deleter
	> const &right
);

/**
\brief Checks if one unique ptr is less than the other

\ingroup fcpptsmartptr

Checks if \a left is less than \a right, comparing their pointers with
<code>std::less</code>.

Pointers to \a Type1 and to \a Type2 must be comparable using
<code>std::less</code>.

\param left The left argument

\param right The right argument
*/
template<
	typename Type1,
	typename Type2,
	typename Deleter
>
bool
operator<(
	fcppt::unique_ptr<
		Type1,
		Deleter
	> const &left,
	fcppt::unique_ptr<
		Type2,
		Deleter
	> const &right
);

}

#endif
