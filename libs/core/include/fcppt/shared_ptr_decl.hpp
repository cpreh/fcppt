//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SHARED_PTR_DECL_HPP_INCLUDED
#define FCPPT_SHARED_PTR_DECL_HPP_INCLUDED

#include <fcppt/shared_ptr_fwd.hpp>
#include <fcppt/unique_ptr_fwd.hpp>
#include <fcppt/weak_ptr_fwd.hpp>
#include <fcppt/detail/make_shared_wrapper_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <memory>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief A shared pointer class that gets the deleter as a template parameter

\ingroup fcpptsmartptr

A shared pointer shares ownership of a single pointer with other shared
pointers. How many shared pointers actually own a pointer is kept track of as a
reference count. Copying shared pointers increases the count by one, while
destroying shared pointers decrases the count by one. If the count reaches
zero, the object that is pointed to will be destroyed.

The class is implemented using <code>std::shared_ptr</code>, so it will inherit
most of its traits. This means that the class also uses type erasure for its
deleter and internal ref count.

\tparam Type The type the shared pointer points to

\tparam Deleter A deleter class that must be callable with a pointer to Type.
*/
template<
	typename Type,
	typename Deleter
>
class shared_ptr
{
public:
	/**
	\brief The type of the <code>std::shared_ptr</code> used to implement
	this class
	*/
	typedef std::shared_ptr<
		Type
	> impl_type;

	/**
	\brief The element type, which is \a Type
	*/
	typedef typename impl_type::element_type element_type;

	/**
	\brief Same as element_type
	*/
	typedef element_type value_type;

	/**
	\brief The pointer type, same as <code>value_type *</code>
	*/
	typedef element_type *pointer;

	/**
	\brief The reference type, same as <code>value_type &</code>
	*/
	typedef
	std::add_lvalue_reference_t<
		element_type
	>
	reference;

	/**
	\brief Constructs a shared_ptr from a compatible pointer type

	Contructs a shared_ptr from \a pointer, taking ownership over it.

	\tparam Other A type, so that <code>Other *</code> is implicitly
	convertible to <code>Type *</code>

	\param pointer The pointer to take ownership of
	*/
	template<
		typename Other
	>
	explicit
	shared_ptr(
		Other *pointer
	);

	/**
	\brief Constructs a shared_ptr from a compatible pointer type and allocator

	Contructs a shared_ptr from \a pointer, taking ownership over it, also
	using \a allocator to manage the reference counts.

	\tparam Other A type, so that <code>Other *</code> is implicitly
	convertible to <code>Type *</code>

	\tparam Alloc An allocator type

	\param pointer The pointer to take ownership of

	\param allocator The allocator to use for reference counting
	*/
	template<
		typename Other,
		typename Alloc
	>
	shared_ptr(
		Other *pointer,
		Alloc const &allocator
	);

	/**
	\brief Constructs a shared_ptr from a compatible weak_ptr

	Constructs a shared_ptr from the weak_ptr \a ref. If the weak_ptr still
	refers to a shared_ptr, then this constructor will behave as if the
	copy constructor with that shared_ptr was invoked instead. Otherwise,
	the shared_ptr will be constructed as empty.

	\tparam Other A type, so that <code>Other *</code> is implicitly
	convertible to <code>Type *</code>

	\param ref The weak_ptr to copy from
	*/
	template<
		typename Other
	>
	explicit
	shared_ptr(
		fcppt::weak_ptr<
			Other,
			Deleter
		> const &ref
	);

	/**
	\brief Constructs a shared_ptr from a compatible shared_ptr

	Constructs a shared_ptr from \a ref. If \a ref is empty, then the
	constructed shared_ptr will be empty. Otherwise, the reference count
	will be increased by one.

	\tparam Other A type, so that <code>Other *</code> is implicitly
	convertible to <code>Type *</code>

	\param ref The shared pointer to copy from
	*/
	template<
		typename Other
	>
	shared_ptr(
		fcppt::shared_ptr<
			Other,
			Deleter
		> const &ref
	);

	/**
	\brief Constructs a shared_ptr that shares ownership with another

	Constructs a shared_ptr that shares ownership with \a ref and stores \a
	data. This is useful for implementing dynamic_pointer_cast and so on.

	\tparam Other A type, so that <code>Other *</code> is implicitly
	convertible to <code>Type *</code>

	\param ref The shared pointer to share ownership with

	\param data The pointer this shared_ptr will point to
	*/
	template<
		typename Other
	>
	shared_ptr(
		fcppt::shared_ptr<
			Other
		> const &ref,
		pointer data
	);

	template<
		typename Other
	>
	explicit
	shared_ptr(
		std::unique_ptr<
			Other,
			Deleter
		> &&ref
	);

	/**
	\brief Constructs a shared_ptr from a compatible unique_ptr

	Constructs a shared_ptr from the unique_ptr \a ref. If the unique_ptr
	holds a pointer, then this shared_ptr will take ownership. Otherwise,
	the shared_ptr will be empy.

	\tparam Other A type, so that <code>Other *</code> is implicitly
	convertible to <code>Type *</code>

	\param ref The unique_ptr to take ownership from
	*/
	template<
		typename Other
	>
	explicit
	shared_ptr(
		fcppt::unique_ptr<
			Other,
			Deleter
		> &&ref
	);

	/**
	\brief Assigns a shared_ptr from a compatible shared_ptr

	Assigns this shared_ptr from \a ref. In any case, the reference count
	of the current shared_ptr will be decreased by one, possibly leading to
	the destruction of the object. If \a ref is empty, then this shared_ptr
	will also be empty. Otherwise, the shared count of \a ref will be
	increased by one and this shared_ptr will also take ownership.

	\tparam Other A type, so that <code>Other *</code> is implicitly
	convertible to <code>Type *</code>

	\param ref The shared_ptr to assign from
	*/
	template<
		typename Other
	>
	shared_ptr &
	operator=(
		fcppt::shared_ptr<
			Other,
			Deleter
		> const &ref
	);

	/**
	\brief Assigns a shared_ptr from a compatible unique_ptr

	Assigns this shared_ptr from \a ref. In any case, the reference count
	of the current shared_ptr will be decreased by one, possibly leading to
	the destruction of the object. If \a ref is empty, then this shared_ptr
	will also be empty. Otherwise, this shared_ptr will take onwerhsip of
	the pointer from \a ref.

	\tparam Other A type, so that <code>Other *</code> is implicitly
	convertible to <code>T *</code>

	\param ref The shared_ptr to assign from
	*/
	template<
		typename Other
	>
	shared_ptr &
	operator=(
		fcppt::unique_ptr<
			Other,
			Deleter
		> &&ref
	);

	/**
	\brief Destroys this shared_ptr

	If this shared_ptr is empty, nothing happens. Otherwise, the shared
	count will be decreased by one, possibly leading to the destruction of
	the object. Deletion will be done calling Deleter().
	*/
	~shared_ptr();

	/**
	\brief Dereferences the owned pointer

	Returns a reference to the owned object.

	\warning The behaviour is undefined if the shared_ptr is empty.
	*/
	reference
	operator* () const;

	/**
	\brief Dereferences a member of the owned object

	Returns a pointer to the owned object.

	\warning The behaviour is undefined if the shared_ptr is empty.
	*/
	pointer
	operator-> () const;

	/**
	\brief Returns a pointer to the owned object

	Returns a pointer to the owned object or the null pointer if the
	shared_ptr is empty.
	*/
	pointer
	get_pointer() const;

	/**
	\brief Returns if this shared_ptr is the only owner of the current object

	If the shared_ptr is empty, the behaviour is unspecified. Otherwise,
	true will be returned if this shared_ptr is the only shared_ptr that
	takes part in the ownership of the currently owned object.
	*/
	bool
	unique() const;

	/**
	\brief The use count

	If this shared_ptr is empty, 0 will be returned. Otherwise, the number
	of shared_ptr objects owning the currently owned object will be
	returned.

	\note This type is <code>long</code> because
	<code>std::shared_ptr</code> also uses <code>long</code>.
	*/
	long
	use_count() const;

	/**
	\brief Swaps the shared_ptr

	Swaps the shared_ptr with \a other.

	\param other The shared_ptr to swap with
	*/
	void
	swap(
		shared_ptr &other
	);

	/**
	\brief Returns the underlying <code>std::shared_ptr</code> object
	*/
	impl_type
	std_ptr() const;

// \cond
	// Intentionally not explicit
	template<
		typename Other
	>
	shared_ptr(
		fcppt::detail::make_shared_wrapper<
			Other
		> &&
	);
// \endcond
private:
	impl_type impl_;

	// This is used to create a shared_ptr from a weak_ptr
	template<
		typename Other
	>
	explicit
	shared_ptr(
		std::shared_ptr<
			Other
		>
	);

	template<
		typename Other,
		typename OtherDeleter
	>
	friend class shared_ptr;

	friend class fcppt::weak_ptr<
		Type,
		Deleter
	>;
};

/**
\brief Compares two shared ptrs for equality

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
	fcppt::shared_ptr<
		Type1,
		Deleter
	> const &left,
	fcppt::shared_ptr<
		Type2,
		Deleter
	> const &right
);

/**
\brief Compares two shared ptrs for inequality

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
	fcppt::shared_ptr<
		Type1,
		Deleter
	> const &left,
	fcppt::shared_ptr<
		Type2,
		Deleter
	> const &right
);

/**
\brief Checks if one shared ptr is less than the other

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
	fcppt::shared_ptr<
		Type1,
		Deleter
	> const &left,
	fcppt::shared_ptr<
		Type2,
		Deleter
	> const &right
);

/**
\brief Swaps two shared pointers

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
	fcppt::shared_ptr<
		Type,
		Deleter
	> &left,
	fcppt::shared_ptr<
		Type,
		Deleter
	> &right
);

}

#endif
