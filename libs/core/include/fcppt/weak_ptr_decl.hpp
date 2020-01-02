//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_WEAK_PTR_DECL_HPP_INCLUDED
#define FCPPT_WEAK_PTR_DECL_HPP_INCLUDED

#include <fcppt/shared_ptr_fwd.hpp>
#include <fcppt/weak_ptr_fwd.hpp>
#include <fcppt/optional/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <memory>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief A weak reference to an object owned by a shared pointer

\ingroup fcpptsmartptr

A weak pointer contributes to the weak reference count of on object owned by
shared pointers. The difference is that a weak pointer won't stop the object
from being destructed. Such a weak pointer can be used to observe if there are
any shared pointers left.

\tparam Type The type the weak pointer points to

\tparam Deleter A deleter class that must be callable with a pointer to Type.
*/
template<
	typename Type,
	typename Deleter
>
class weak_ptr
{
public:
	/**
	\brief The type if the <code>std::weak_ptr</code> used to implement
	this class
	*/
	typedef
	std::weak_ptr<
		Type
	>
	impl_type;

	/**
	\brief The corresponding shared pointer class
	*/
	typedef
	fcppt::shared_ptr<
		Type,
		Deleter
	>
	shared_ptr;

	/**
	\brief The element type, which is \a Type
	*/
	typedef
	Type
	element_type;

	/**
	\brief Constructs an empty weak ptr
	*/
	weak_ptr();

	/**
	\brief Constructs a weak_ptr from a compatible weak_ptr type

	Constructs a weak_ptr from the weak_ptr \a ref. This weak_ptr will
	belong to the same shared_ptrs as \a ref does.

	\tparam Other A type, so that <code>Other *</code> is implicitly
	convertible to <code>Type *</code>

	\param ref The weak_ptr to copy
	*/
	template<
		typename Other
	>
	weak_ptr(
		fcppt::weak_ptr<
			Other,
			Deleter
		> const &ref
	);

	/**
	\brief Constructs a weak_ptr from a compatible shared_ptr

	Constructs a weak_ptr from the shared_ptr \a ref which will keep track
	of the shared count of the shared_ptr.

	\tparam Other A type, so that <code>Other *</code> is implicitly
	convertible to <code>Type *</code>

	\param ref The shared_ptr to monitor
	*/
	template<
		typename Other
	>
	weak_ptr(
		fcppt::shared_ptr<
			Other,
			Deleter
		> const &ref
	);

	/**
	\brief Returns a shared_ptr pointing to the shared object of this
	weak_ptr

	If the shared object is still alive (which means that the reference
	count is still greater than zero), then a new shared_ptr also owning
	that object will be returned. If all shared_ptrs have been destroyed,
	then an empty optional will be returned.
	*/
	fcppt::optional::object<
		shared_ptr
	>
	lock() const;

	/**
	\brief The use count

	If this weak_ptr is empty, zero will be returned. Otherwise the shared
	count of the shared object will be returned.

	\note This type is <code>long</code> because
	<code>std::shared_ptr</code> also uses <code>long</code>.
	*/
	long
	use_count() const
	noexcept;

	/**
	\brief Returns if the weak_ptr still points to a shared object

	If this weak_ptr is empty, false will be returned. Otherwise if the
	shared count is still greater than zero, true will be returned.
	*/
	bool
	expired() const
	noexcept;

	/**
	\brief Swaps the weak_ptr

	Swaps the weak_ptr with \a other.

	\param other The shared_ptr to swap with
	*/
	void
	swap(
		weak_ptr &other
	)
	noexcept;

	/**
	\brief Returns the underlying <code>std::weak_ptr</code> object
	*/
	impl_type
	std_ptr() const;
private:
	impl_type impl_;
};

/**
\brief Checks if one weak ptr is less than the other

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
	fcppt::weak_ptr<
		Type1,
		Deleter
	> const &left,
	fcppt::weak_ptr<
		Type2,
		Deleter
	> const &right
)
noexcept;

/**
\brief Swaps two weak pointers

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
	fcppt::weak_ptr<
		Type,
		Deleter
	> &left,
	fcppt::weak_ptr<
		Type,
		Deleter
	> &right
)
noexcept;

}

#endif
