//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SCOPED_PTR_DECL_HPP_INCLUDED
#define FCPPT_SCOPED_PTR_DECL_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <fcppt/scoped_ptr_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <memory>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief A scoped pointer class that gets the deleter as a template parameter

\ingroup fcpptsmartptr

A scoped pointer is a special smart pointer that is not copyable. The
difference to owning an object by scoped ptr instead of by value is that it
doesn't have to be complete. Also, a scoped ptr is a perfect candidate for
owning an object created by a factory that returns a unique ptr.

\tparam Type The type the scoped pointer points to

\tparam Deleter A deleter class that must be callable with a pointer to Type.
*/
template<
	typename Type,
	typename Deleter
>
class scoped_ptr
{
	FCPPT_NONCOPYABLE(
		scoped_ptr
	);
public:
	/**
	\brief The element type, which is \a Type
	*/
	typedef Type element_type;

	/**
	\brief The reference type
	*/
	typedef typename std::add_lvalue_reference<
		Type
	>::type reference;

	/**
	\brief The pointer type, same as <code>value_type *</code>
	*/
	typedef Type *pointer;

	/**
	\brief Constructs an empty scoped_ptr
	*/
	scoped_ptr();

	/**
	\brief Constructs a scoped_ptr from a compatible pointer type

	Contructs a scoped_ptr from \a pointer, taking ownership over it.

	\tparam Other A type, so that <code>Other *</code> is implicitly
	convertible to <code>Type *</code>

	\param pointer The pointer to take ownership of
	*/
	template<
		typename Other
	>
	explicit
	scoped_ptr(
		Other *pointer
	);

	/**
	\brief Constructs a scoepd_ptr from a compatible unique_ptr

	Constructs a scoped_ptr from the unique_ptr \a ref. If the unique_ptr
	holds a pointer, then this scoped_ptr will take ownership. Otherwise,
	the scoped_ptr will be empy.

	\tparam Other A type, so that <code>Other *</code> is implicitly
	convertible to <code>Type *</code>

	\tparam OtherDeleter A deleter that must be convertible to \a Deleter

	\param ref The unique_ptr to take ownership from
	*/
	template<
		typename Other,
		typename OtherDeleter
	>
	explicit
	scoped_ptr(
		std::unique_ptr<
			Other,
			OtherDeleter
		> &&ref
	);

	~scoped_ptr();

	/**
	\brief Resets this scoped_ptr

	If this scoped_ptr is empty, nothing happens. Otherwise, the owned
	object will be destroyed. In any case, this scoped_ptr will be empty.
	*/
	void
	reset();

	/**
	\brief Resets this scoped_ptr from a compatible pointer type

	If this scoped_ptr is empty, no destruction happens. Otherwise, the
	previously owned object will be destroyed. After that, this scoped_ptr
	will take ownership of \a pointer.

	\tparam Other A type, so that <code>Other *</code> is implicitly
	convertible to <code>T *</code>

	\param pointer The pointer to take ownership of
	*/
	template<
		typename Other
	>
	void
	reset(
		Other *pointer
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
	scoped_ptr is empty.
	*/
	pointer
	get() const;

	/**
	\brief Swaps the unique_ptr

	Swaps the scoped_ptr with \a other.

	\param other The scoped_ptr to swap with
	*/
	void
	swap(
		scoped_ptr &other
	);

	/**
	\brief Takes ownership of a compatible unique_ptr

	If this scoped_ptr is not empty, then the owned object will be
	destroyed. Afterwards, it takes ownership of \a ptr. If \a ptr
	is empty, then this scoped_ptr will be empty.

	\tparam Other A type, so that <code>Other *</code> is implicitly
	convertible to <code>T *</code>

	\tparam OtherDeleter A deleter that must be convertible to \a Deleter

	\param ptr The unique to take ownership of
	*/
	template<
		typename Other,
		typename OtherDeleter
	>
	void
	take(
		std::unique_ptr<
			Other,
			OtherDeleter
		> &&ptr
	);

	/**
	\brief Releases the ownership

	Returns a unique_ptr of the currently owned pointer, and makes this
	scoped_ptr empty. If this scoped_ptr was already empty, then the
	returned unique_ptr will also be empty.
	*/
	std::unique_ptr<
		Type,
		Deleter
	>
	release();

	/**
	\brief Explicit bool conversion

	Returns true if the <code>get() == nullptr</code>
	*/
	explicit
	operator bool() const;
private:
	pointer ptr_;
};

/**
\brief Swaps two scoped pointers

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
	fcppt::scoped_ptr<
		Type,
		Deleter
	> &left,
	fcppt::scoped_ptr<
		Type,
		Deleter
	> &right
);

}

#endif
