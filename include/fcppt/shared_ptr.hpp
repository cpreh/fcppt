/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2009 Carl Philipp Reh (sefi@s-e-f-i.de)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/


#ifndef SGE_SHARED_PTR_HPP_INCLUDED
#define SGE_SHARED_PTR_HPP_INCLUDED

#include <sge/shared_ptr_fwd.hpp>
#include <sge/weak_ptr_fwd.hpp>
#include <sge/auto_ptr.hpp>
#include <boost/shared_ptr.hpp>

namespace sge
{

template<
	typename T,
	template<
		typename
	> class Deleter
>
class shared_ptr {
public:
	typedef boost::shared_ptr<T> impl_type;
	typedef typename impl_type::element_type element_type;
	typedef typename impl_type::value_type value_type;
	typedef typename impl_type::pointer pointer;
	typedef typename impl_type::reference reference;

	shared_ptr()
	: impl()
	{}

	template<class Y>
	explicit shared_ptr( Y *const p )
	: impl(p, deleter())
	{}

	template<class Y, class D, class A> shared_ptr( Y *const p, const A& a )
	: impl(p, deleter(), a)
	{}

	template<
		typename Y
	>
	explicit shared_ptr(weak_ptr<Y, Deleter> const & r)
	: impl(r)
	{}

	template<class Y>
	shared_ptr(shared_ptr<Y> const & r)
	: impl(r.boost_ptr())
	{}

	template<class Y>
	shared_ptr(shared_ptr<Y> const & r, boost::detail::static_cast_tag)
	: impl(r.boost_ptr(), boost::detail::static_cast_tag())
	{}

	template<class Y>
	shared_ptr(shared_ptr<Y> const & r, boost::detail::const_cast_tag)
	: impl(r.boost_ptr(), boost::detail::const_cast_tag())
	{}

	template<class Y>
	shared_ptr(shared_ptr<Y> const & r, boost::detail::dynamic_cast_tag)
	: impl(r.boost_ptr(), boost::detail::dynamic_cast_tag())
	{}

	template<class Y>
	shared_ptr(shared_ptr<Y> const & r, boost::detail::polymorphic_cast_tag)
	: impl(r.boost_ptr(), boost::detail::polymorphic_cast_tag())
	{}

	template<class Y>
	explicit shared_ptr(auto_ptr<Y> r)
	//: impl(r)
	{
		impl = r;
	}

	template<class Y>
	shared_ptr & operator=(shared_ptr<Y> const & r)
	{
		impl = r.impl;
		return *this;
	}

	template<class Y>
	shared_ptr & operator=( auto_ptr<Y> r )
	{
 		impl = r;
		return *this;
	}

	void reset()
	{
		impl.reset();
	}

	template<class Y>
	void reset(Y *const p)
	{
        	impl.reset(p, deleter());
	}

	template<class Y, class A> void reset( Y *const p, const A& a )
	{
		impl.reset(p, deleter(), a);
	}

	reference operator* () const // never throws
	{
		return *impl;
	}

	pointer operator-> () const // never throws
	{
		return impl.operator->();
	}

	pointer get() const // never throws
	{
        	return impl.get();
	}

	typedef typename impl_type::unspecified_bool_type unspecified_bool_type;

	operator unspecified_bool_type() const // never throws
	{
		return impl;
	}

	bool operator! () const // never throws
	{
		return !impl;
	}

	bool unique() const // never throws
	{
		return impl.unique();
	}

	long use_count() const // never throws
	{
		return impl.use_count();
	}

	void swap(shared_ptr<T> & other) // never throws
	{
		std::swap(impl, other.impl);
 	}

	impl_type const
	boost_ptr() const
	{
		return impl;
	}
private:
	impl_type impl;

	static Deleter<T> deleter()
	{
		return Deleter<T>();
	}

	// this is used to create a shared_ptr
	// from a weak_ptr
	template<
		typename U
	>
	explicit shared_ptr(
		boost::shared_ptr<U> const &p)
	:
		impl(p)
	{}


	template<
		typename Other,
		template<
			typename
		> class OtherDeleter
	>
	friend class shared_ptr;

	friend class weak_ptr<T, Deleter>;
};

template<
	typename T,
	typename U,
	template<
		typename
	> class Deleter
>
bool operator==(
	shared_ptr<T, Deleter> const &a,
	shared_ptr<U, Deleter> const &b)
{
	return a.boost_ptr() == b.boost_ptr();
}

template<
	typename T,
	typename U,
	template<
		typename
	> class Deleter
>
bool operator!=(
	shared_ptr<T, Deleter> const &a,
	shared_ptr<U, Deleter> const &b)
{
	return !(a==b);
}

template<
	typename T,
	typename U,
	template<
		typename
	> class Deleter
>
bool operator<(
	shared_ptr<T, Deleter> const &a,
	shared_ptr<U, Deleter> const &b)
{
	return a.boost_ptr() < b.boost_ptr();
}

template<
	typename T,
	typename U,
	template<
		typename
	> class Deleter
>
void
swap(
	shared_ptr<T, Deleter> &a,
	shared_ptr<T, Deleter> &b)
{
	a.swap(b);
}

template<
	typename T,
	typename U,
	template<
		typename
	> class Deleter
>
shared_ptr<T, Deleter> const
static_pointer_cast(
	shared_ptr<U, Deleter> const &r)
{
	return shared_ptr<T, Deleter>(
		r,
		boost::detail::static_cast_tag());
}

template<
	typename T,
	typename U,
	template<
		typename
	> class Deleter
>
shared_ptr<T, Deleter> const
const_pointer_cast(
	shared_ptr<U, Deleter> const &r)
{
	return shared_ptr<T, Deleter>(
		r,
		boost::detail::const_cast_tag());
}

template<
	typename T,
	typename U,
	template<
		typename
	> class Deleter
>
shared_ptr<T, Deleter> const
dynamic_pointer_cast(
	shared_ptr<U, Deleter> const &r)
{
	return shared_ptr<T, Deleter>(
		r,
		boost::detail::dynamic_cast_tag());
}

template<
	typename T,
	typename U,
	template<
		typename
	> class Deleter
>
shared_ptr<T, Deleter> const
polymorphic_pointer_cast(
	shared_ptr<U, Deleter> const &r)
{
	return shared_ptr<T, Deleter>(
		r,
		boost::detail::polymorphic_cast_tag());
}

/*
template<
	typename T,
	template<
		typename
	> class Deleter
>
T *pointer(
	shared_ptr<T, Deleter> const & p)
{
    return p.get();
}
*/

template<
	typename Ch,
	typename Traits,
	typename T,
	template<
		typename
	> class Deleter
>
std::basic_ostream<Ch, Traits> &
operator<< (
	std::basic_ostream<Ch, Traits> &os,
	shared_ptr<T, Deleter> const & p)
{
	os << p.get();
	return os;
}

}

#endif
