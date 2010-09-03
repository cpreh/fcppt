//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SHARED_PTR_DECL_HPP_INCLUDED
#define FCPPT_SHARED_PTR_DECL_HPP_INCLUDED

#include <fcppt/shared_ptr_fwd.hpp>
#include <fcppt/unique_ptr_fwd.hpp>
#include <fcppt/weak_ptr_fwd.hpp>
#include <boost/shared_ptr.hpp>
#include <iosfwd>

namespace fcppt
{

/// A shared_ptr class that get's the deleter as template parameter
/* The class is implemented using boost::shared_ptr so it will inherit
 * all its traits. This means that the class also uses type erasure
 * for its deleter and internal ref count.
*/
template<
	typename T,
	template<
		typename
	> class Deleter
>
class shared_ptr
{
public:
	typedef boost::shared_ptr<T> impl_type;
	typedef typename impl_type::element_type element_type;
	typedef typename impl_type::value_type value_type;
	typedef typename impl_type::pointer pointer;
	typedef typename impl_type::reference reference;

	shared_ptr();

	template<
		typename Y
	>
	explicit shared_ptr(
		Y *p
	);

	template<
		typename Y,
		typename D,
		typename A
	>
	shared_ptr(
		Y *p,
		A const &a
	);

	template<
		typename Y
	>
	explicit shared_ptr(
		weak_ptr<Y, Deleter> const &r
	);

	template<
		typename Y
	>
	shared_ptr(
		shared_ptr<Y> const &r
	);

	template<
		typename Y
	>
	shared_ptr(
		shared_ptr<Y> const &r,
		boost::detail::static_cast_tag
	);

	template<
		typename Y
	>
	shared_ptr(
		shared_ptr<Y> const &r,
		boost::detail::const_cast_tag
	);

	template<
		typename Y
	>
	shared_ptr(
		shared_ptr<Y> const &r,
		boost::detail::dynamic_cast_tag
	);

	template<
		typename Y
	>
	shared_ptr(
		shared_ptr<Y> const &r,
		boost::detail::polymorphic_cast_tag
	);

	template<
		typename Y
	>
	explicit shared_ptr(
		unique_ptr<Y, Deleter> r
	);

	template<
		typename Y
	>
	shared_ptr &
	operator=(
		shared_ptr<Y> const &r
	);

	template<
		typename Y
	>
	shared_ptr &
	operator=(
		unique_ptr<Y, Deleter> r
	);

	~shared_ptr();

	void
	reset();

	template<
		typename Y
	>
	void
	reset(
		Y *p
	);

	template<
		typename Y,
		typename A
	>
	void
	reset(
		Y *p,
		A const &a
	);

	reference
	operator* () const;

	pointer
	operator-> () const;

	pointer
	get() const;

	typedef typename impl_type::unspecified_bool_type unspecified_bool_type;

	operator unspecified_bool_type() const;

	bool
	operator! () const;

	bool
	unique() const;

	long
	use_count() const;

	void
	swap(
		shared_ptr<T> &other
	);

	impl_type const
	boost_ptr() const;
private:
	impl_type impl;

	static Deleter<T> const
	deleter();

	// this is used to create a shared_ptr
	// from a weak_ptr
	template<
		typename U
	>
	explicit shared_ptr(
		boost::shared_ptr<U> const &p
	);

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
bool
operator==(
	shared_ptr<T, Deleter> const &a,
	shared_ptr<U, Deleter> const &b
);

template<
	typename T,
	typename U,
	template<
		typename
	> class Deleter
>
bool
operator!=(
	shared_ptr<T, Deleter> const &a,
	shared_ptr<U, Deleter> const &b
);

template<
	typename T,
	typename U,
	template<
		typename
	> class Deleter
>
bool
operator<(
	shared_ptr<T, Deleter> const &a,
	shared_ptr<U, Deleter> const &b
);

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
	shared_ptr<T, Deleter> &b
);

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
	shared_ptr<T, Deleter> const & p
);

}

#endif
