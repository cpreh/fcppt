// Copyright 2009 Howard Hinnant, Ion Gazta&ntilde;aga.
// Copyright 2010-2012 Carl Philipp Reh
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
// See http://www.boost.org/libs/foreach for documentation


#ifndef FCPPT_UNIQUE_PTR_DECL_HPP_INCLUDED
#define FCPPT_UNIQUE_PTR_DECL_HPP_INCLUDED

#include <fcppt/null_ptr.hpp>
#include <fcppt/unique_ptr_fwd.hpp>
#include <fcppt/detail/rvalue_ref.hpp>
#include <fcppt/preprocessor/disable_icc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/type_traits/is_convertible.hpp>
#include <boost/utility/enable_if.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_ICC_WARNING(2289)
FCPPT_PP_DISABLE_ICC_WARNING(2304)

/**
\brief A unique pointer class, designed to emulate <em>C++11's</em>
<code>std::unique_ptr</code>

A unique pointer is similar to <code>std::auto_ptr</code> (which is deprecated
in C++11), because only one object holds ownership over a pointer. The
difference is that unique_ptr disallows certain things that auto_ptr allowed
(like moving from lvalue).

\tparam Type The type the shared pointer points to

\tparam Deleter A deleter class that must be callable with a pointer to T.
*/
template<
	typename Type,
	typename Deleter
>
class unique_ptr
{
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
	\brief The reference type, same as <code>value_type &</code>
	*/
	typedef element_type &reference;

	/**
	\brief The pointer type, same as <code>value_type *</code>
	*/
	typedef element_type *pointer;
private:
	pointer ptr_;

	struct nat
	{
		int for_bool_;
	};

	typedef int (nat::*bool_type);

	unique_ptr(
		unique_ptr &
	);

	unique_ptr &
	operator=(
		unique_ptr &
	);
public:
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
		> other,
		typename boost::enable_if<
			boost::is_convertible<
				typename fcppt::unique_ptr<
					Other
				>::pointer,
				pointer
			>
		>::type * = fcppt::null_ptr()
	);

	/**
	\brief Destroys the unique_ptr

	If the unique_ptr is empty, nothing happens. Otherwise, the owned
	object will be destroyed, which will be done by Deleter().
	*/
	~unique_ptr();

	/**
	\brief TODO: WHY?
	*/
	unique_ptr &
	operator=(
		bool_type
	);

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

	reference
	operator*() const;

	pointer
	operator->() const;

	pointer
	get() const;

	operator bool_type() const;

	void
	reset(
		pointer = pointer()
	);

	pointer
	release();

	void
	swap(
		unique_ptr &
	);
};
FCPPT_PP_POP_WARNING

template<
	typename Type,
	typename Deleter
>
void
swap(
	fcppt::unique_ptr<
		Type,
		Deleter
	> &,
	fcppt::unique_ptr<
		Type,
		Deleter
	> &
);

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
	> const &,
	fcppt::unique_ptr<
		Type2,
		Deleter
	> const &
);

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
	> const &,
	fcppt::unique_ptr<
		Type2,
		Deleter
	> const &
);

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
	> const &,
	fcppt::unique_ptr<
		Type2,
		Deleter
	> const &
);

}

#endif
