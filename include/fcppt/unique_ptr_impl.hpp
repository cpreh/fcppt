#ifndef FCPPT_UNIQUE_PTR_IMPL_HPP_INCLUDED
#define FCPPT_UNIQUE_PTR_IMPL_HPP_INCLUDED

#include <fcppt/unique_ptr_decl.hpp>

template<
	typename T,
	template<
		typename
	> class Deleter
>
fcppt::unique_ptr<T, Deleter>::
operator detail_unique_ptr::rv<
	unique_ptr
>()
{
	return
		detail_unique_ptr::rv<
			unique_ptr
		>(
			*this
		);
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
fcppt::unique_ptr<T, Deleter>::unique_ptr(
	detail_unique_ptr::rv<unique_ptr> r
)
:
	ptr_(
		r->release(),
		fcppt::forward<
			deleter_type
		>(
			r->get_deleter()
		)
	)
{}

template<
	typename T,
	template<
		typename
	> class Deleter
>
fcppt::unique_ptr<T, Deleter> &
fcppt::unique_ptr<T, Deleter>::operator=(
	detail_unique_ptr::rv<unique_ptr> r
)
{
       	reset(r->release());

        ptr_.second() = fcppt::move(r->get_deleter());

        return *this;
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
fcppt::unique_ptr<T, Deleter>::unique_ptr()
{
	BOOST_STATIC_ASSERT(
		!boost::is_reference<
			deleter_type
		>::value
	);

	BOOST_STATIC_ASSERT(
		!boost::is_pointer<
			deleter_type
		>::value
	);
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
fcppt::unique_ptr<T, Deleter>::unique_ptr(
	pointer const p
)
:
	ptr_(p)
{
	BOOST_STATIC_ASSERT(
		!boost::is_reference<
			deleter_type
		>::value
	);

	BOOST_STATIC_ASSERT(
		!boost::is_pointer<
			deleter_type
		>::value
	);
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
fcppt::unique_ptr<T, Deleter>::unique_ptr(
	pointer const p,
	typename mpl::if_<
		is_reference<D>,
		volatile typename boost::remove_reference<D>::type &,
		D
	>::type const d
)
:
	ptr_(
		fcppt::move(
			p
		),
		fcppt::forward<D>(
			const_cast<
				typename boost::add_reference<D>::type
			>(
				d
			)
		)
	)
{}

template<
	typename T,
	template<
		typename
	> class Deleter
>
template<
	typename U,
	typename E
>
fcppt::unique_ptr<T, Deleter>::unique_ptr(
	unique_ptr<U, E> u,
	typename enable_if_c<
                !boost::is_array<U>::value
		&&
		detail_unique_ptr::is_convertible<
			typename unique_ptr<U>::pointer,
			pointer
		>::value
		&&
		detail_unique_ptr::is_convertible<
			E,
			deleter_type
		>::value
		&&
		(
			!boost::is_reference<
				deleter_type
			>::value
			||
			boost::is_same<
				deleter_type,
				E
			>::value
		)
	>::type* = 0
)
:
	ptr_(
		u.release(),
		fcppt::forward<D>(
			fcppt::forward<E>(
				u.get_deleter()
			)
		)
	)
{}

template<
	typename T,
	template<
		typename
	> class Deleter
>
fcppt::unique_ptr<T, Deleter>::~unique_ptr()
{
	reset();
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
fcppt::unique_ptr<T, Deleter> &
fcppt::unique_ptr<T, Deleter>::operator=(
	int nat::*
)
{
	reset();

	return *this;
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
template<
	typename U,
	typename E
>
fcppt::unique_ptr<T, Deleter> &
fcppt::unique_ptr<T, Deleter>::operator=(
	unique_ptr<U, E> u
)
{
	reset(
		u.release()
	);

	ptr_.second() =
		fcppt::move(
			u.get_deleter()
		);

	return *this;
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
typename boost::add_reference<T>::type
fcppt::unique_ptr<T, Deleter>::operator*() const
{
	return *get();
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
typename fcppt::unique_ptr<T, Deleter>::pointer
fcppt::unique_ptr<T, Deleter>::operator->() const
{
	return get();
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
typename fcppt::unique_ptr<T, Deleter>::pointer
fcppt::unique_ptr<T, Deleter>::get() const
{
	return ptr_.first();
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
typename fcppt::unique_ptr<T, Deleter>::deleter_reference
fcppt::unique_ptr<T, Deleter>::get_deleter()
{
	return ptr_.second();
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
typename fcppt::unique_ptr<T, Deleter>::deleter_const_reference
fcppt::unique_ptr<T, Deleter>::get_deleter() const
{
	return ptr_.second();
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
fcppt::unique_ptr<T, Deleter>::
operator int nat::*() const
{
	return get() ? &nat::for_bool_ : 0;
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
void
fcppt::unique_ptr<T, Deleter>::reset(
	pointer const p = pointer()
)
{
       	pointer const t = get();

	if (t != pointer())
		get_deleter()(t);

	ptr_.first() = p;
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
typename fcppt::unique_ptr<T, Deleter>::pointer
fcppt::unique_ptr<T, Deleter>::release()
{
	pointer const tmp = get();

	ptr_.first() = pointer();

	return tmp;
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
void
fcppt::unique_ptr<T, Deleter>::swap(
	unique_ptr &u
)
{
	detail_unique_ptr::swap(
		ptr_,
		u.ptr_
	);
}

template<
	typename T,
	template<
		typename
	> class D
>
inline
void
fcppt::swap(
	unique_ptr<T, D> &x,
	unique_ptr<T, D> &y
)
{
	x.swap(y);
}

template<
	typename T1,
	typename T2,
	template<
		typename
	> class D
>
inline
bool
fcppt::operator==(
	unique_ptr<T1, D> const &x,
	unique_ptr<T2, D> const &y
)
{
	return x.get() == y.get();
}

template<
	typename T1,
	typename T2,
	template<
		typename
	> class D
>
inline
bool
fcppt::operator!=(
	unique_ptr<T1, D> const &x,
	unique_ptr<T2, D> const &y
)
{
	return !(x == y);
}

template<
	typename T1,
	typename T2,
	template<
		typename
	> class D
>
inline
bool
fcppt::operator<(
	unique_ptr<T1, D> const &x,
	unique_ptr<T2, D> const &y
)
{
	return x.get() < y.get();
}

template<
	typename T1,
	typename T2,
	template<
		typename
	> class D
>
inline
bool
fcppt::operator<=(
	unique_ptr<T1, D> const &x,
	unique_ptr<T2, D> const &y
)
{
	return !(y < x);
}

template<
	typename T1,
	typename T2,
	template<
		typename
	> class D
>
inline
bool
fcppt::operator>(
	unique_ptr<T1, D> const &x,
	unique_ptr<T2, D> const &y
)
{
	return y < x;
}

template<
	typename T1,
	typename T2, 
	template<
		typename
	> class D
>
inline
bool
fcppt::operator>=(
	unique_ptr<T1, D> const &x,
	unique_ptr<T2, D> const &y
)
{
	return !(x < y);
}

#endif
