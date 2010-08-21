
#ifndef FCPPT_UNIQUE_PTR_DECL_HPP_INCLUDED
#define FCPPT_UNIQUE_PTR_DECL_HPP_INCLUDED

#include <fcppt/detail_unique_ptr/pointer_type.hpp>
#include <fcppt/detail_unique_ptr/rv.hpp>
#include <fcppt/detail_unique_ptr/is_convertible.hpp>
#include <fcppt/detail_unique_ptr/storage.hpp>
#include <fcppt/unique_ptr_fwd.hpp>
#include <boost/mpl/if.hpp>
#include <boost/type_traits/add_reference.hpp>
#include <boost/type_traits/is_array.hpp>
#include <boost/type_traits/is_reference.hpp>
#include <boost/type_traits/remove_reference.hpp>
#include <boost/utility/enable_if.hpp>

namespace fcppt
{

template<
	typename T,
	template<
		typename
	> class Deleter
>
class unique_ptr
{
public:
	typedef T element_type;

	typedef Deleter<T> deleter_type;

	typedef typename detail_unique_ptr::pointer_type<
    		element_type,
		deleter_type
	>::type pointer;

private:
	detail_unique_ptr::storage<
		pointer,
		deleter_type
	> ptr_;

	typedef typename boost::add_reference<
		deleter_type
	>::type deleter_reference;

	typedef typename boost::add_reference<
		deleter_type const
	>::type deleter_const_reference;

	struct nat
	{
		int for_bool_;
	};

	unique_ptr(
		unique_ptr &
	);

	unique_ptr &
	operator=(
		unique_ptr &
	);
public:
	operator detail_unique_ptr::rv<
		unique_ptr
	>();

	unique_ptr(
		detail_unique_ptr::rv<unique_ptr>
	);

	unique_ptr &
	operator=(
		detail_unique_ptr::rv<unique_ptr>
	);

	unique_ptr();

	explicit unique_ptr(
		pointer
	);

	unique_ptr(
		pointer,
		typename boost::mpl::if_<
			boost::is_reference<
				deleter_type
			>,
			volatile typename boost::remove_reference<
				deleter_type
			>::type &,
			deleter_type	
		>::type
	);

	template<
		typename U
	>
	unique_ptr(
		unique_ptr<U, Deleter> u,
		typename boost::enable_if_c<
	                !boost::is_array<U>::value
			&&
			detail_unique_ptr::is_convertible<
				typename unique_ptr<U>::pointer,
				pointer
			>::value
		>::type* = 0
	);

	~unique_ptr();

	unique_ptr &
	operator=(
		int nat::*
	);

	template<
		typename U
	>
	unique_ptr&
	operator=(
		unique_ptr<U, Deleter>
	);

	typename boost::add_reference<T>::type
	operator*() const;

	pointer
	operator->() const;

	pointer
	get() const;
	
	deleter_reference
	get_deleter();

	deleter_const_reference
	get_deleter() const;

	operator int nat::*() const;

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

#if 0
template <class T, class D>
class unique_ptr<T[], D>
{
public:
    typedef T element_type;
    typedef D deleter_type;
    typedef typename detail_unique_ptr::pointer_type<element_type, deleter_type>::type pointer;

private:
    detail_unique_ptr::unique_ptr_storage<pointer, deleter_type> ptr_;

    typedef typename add_reference<deleter_type>::type deleter_reference;
    typedef typename add_reference<const deleter_type>::type deleter_const_reference;

    struct nat {int for_bool_;};

    unique_ptr(unique_ptr&);
    unique_ptr& operator=(unique_ptr&);

public:
    operator detail_unique_ptr::rv<unique_ptr>() {return detail_unique_ptr::rv<unique_ptr>(*this);}
    unique_ptr(detail_unique_ptr::rv<unique_ptr> r) : ptr_(r->release(), forward<deleter_type>(r->get_deleter())) {}
    unique_ptr& operator=(detail_unique_ptr::rv<unique_ptr> r)
    {
        reset(r->release());
        ptr_.second() = move(r->get_deleter());
        return *this;
    }

    unique_ptr()
        {
            BOOST_STATIC_ASSERT(!is_reference<deleter_type>::value);
            BOOST_STATIC_ASSERT(!is_pointer<deleter_type>::value);
        }

    explicit unique_ptr(pointer p)
        : ptr_(p)
        {
            BOOST_STATIC_ASSERT(!is_reference<deleter_type>::value);
            BOOST_STATIC_ASSERT(!is_pointer<deleter_type>::value);
        }

    unique_ptr(pointer p, typename mpl::if_<is_reference<D>,
                          volatile typename remove_reference<D>::type&, D>::type d)
        : ptr_(move(p), forward<D>(const_cast<typename add_reference<D>::type>(d))) {}

    ~unique_ptr() {reset();}

    T& operator[](size_t i) const {return get()[i];}
    pointer get() const {return ptr_.first();}
    deleter_reference       get_deleter()       {return ptr_.second();}
    deleter_const_reference get_deleter() const {return ptr_.second();}
    operator int nat::*() const {return get() ? &nat::for_bool_ : 0;}

    void reset(pointer p = pointer())
    {
        pointer t = get();
        if (t != pointer())
            get_deleter()(t);
        ptr_.first() = p;
    }

    pointer release()
    {
        pointer tmp = get();
        ptr_.first() = pointer();
        return tmp;
    }

    void swap(unique_ptr& u) {detail_unique_ptr::swap(ptr_, u.ptr_);}
private:
    template <class U>
        explicit unique_ptr(U,
            typename enable_if_c<detail_unique_ptr::is_convertible<U, pointer>::value>::type* = 0);

    template <class U>
        unique_ptr(U, typename mpl::if_<is_reference<D>,
                          volatile typename remove_reference<D>::type&, D>::type,
                          typename enable_if_c<detail_unique_ptr::is_convertible<U, pointer>::value>::type* = 0);
};
#endif

template<
	typename T,
	template<
		typename
	> class D
>
void
swap(
	unique_ptr<T, D> &,
	unique_ptr<T, D> &
);

template<
	typename T1,
	typename T2,
	template<
		typename
	> class D
>
bool
operator==(
	unique_ptr<T1, D> const &,
	unique_ptr<T2, D> const &
);

template<
	typename T1,
	typename T2,
	template<
		typename
	> class D
>
bool
operator!=(
	unique_ptr<T1, D> const &,
	unique_ptr<T2, D> const &
);

template<
	typename T1,
	typename T2,
	template<
		typename
	> class D
>
bool
operator<(
	unique_ptr<T1, D> const &,
	unique_ptr<T2, D> const &
);

template<
	typename T1,
	typename T2,
	template<
		typename
	> class D
>
bool
operator<=(
	unique_ptr<T1, D> const &,
	unique_ptr<T2, D> const &
);

template<
	typename T1,
	typename T2,
	template<
		typename
	> class D
>
bool
operator>(
	unique_ptr<T1, D> const &,
	unique_ptr<T2, D> const &
);

template<
	typename T1,
	typename T2, 
	template<
		typename
	> class D
>
bool
operator>=(
	unique_ptr<T1, D> const &,
	unique_ptr<T2, D> const &
);

}

#endif
