//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SHARED_PTR_DECL_HPP_INCLUDED
#define FCPPT_SHARED_PTR_DECL_HPP_INCLUDED

#include <fcppt/tr1/detail/use_boost_tr1.hpp> // workaround for boost's get_pointer
#include <fcppt/detail/make_shared_wrapper_fwd.hpp>
#include <fcppt/shared_ptr_fwd.hpp>
#include <fcppt/unique_ptr_fwd.hpp>
#include <fcppt/weak_ptr_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/smart_ptr/shared_ptr.hpp>
#include <iosfwd>
#include <fcppt/config/external_end.hpp>

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
		Y *
	);

	template<
		typename Y,
		typename D,
		typename A
	>
	shared_ptr(
		Y *,
		A const &
	);

	template<
		typename Y
	>
	explicit shared_ptr(
		weak_ptr<Y, Deleter> const &
	);

	template<
		typename Y
	>
	shared_ptr(
		shared_ptr<Y> const &
	);

	template<
		typename Y
	>
	shared_ptr(
		shared_ptr<Y> const &,
		boost::detail::static_cast_tag
	);

	template<
		typename Y
	>
	shared_ptr(
		shared_ptr<Y> const &,
		boost::detail::const_cast_tag
	);

	template<
		typename Y
	>
	shared_ptr(
		shared_ptr<Y> const &,
		boost::detail::dynamic_cast_tag
	);

	template<
		typename Y
	>
	shared_ptr(
		shared_ptr<Y> const &,
		boost::detail::polymorphic_cast_tag
	);

	template<
		typename Y
	>
	explicit shared_ptr(
		unique_ptr<Y, Deleter>
	);

	template<
		typename Y
	>
	shared_ptr &
	operator=(
		shared_ptr<Y> const &
	);

	template<
		typename Y
	>
	shared_ptr &
	operator=(
		unique_ptr<Y, Deleter>
	);

	~shared_ptr();

	void
	reset();

	template<
		typename Y
	>
	void
	reset(
		Y *
	);

	template<
		typename Y,
		typename A
	>
	void
	reset(
		Y *,
		A const &
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
		shared_ptr<T> &
	);

	impl_type const
	boost_ptr() const;

	template<
		typename U
	>
	shared_ptr(
		detail::make_shared_wrapper<U>
	);
private:
	impl_type impl_;

	// This is used to create a shared_ptr from a weak_ptr
	template<
		typename U
	>
	explicit shared_ptr(
		boost::shared_ptr<U>
	);

	static Deleter<T> const
	deleter();

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
	shared_ptr<T, Deleter> const &,
	shared_ptr<U, Deleter> const &
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
	shared_ptr<T, Deleter> const &,
	shared_ptr<U, Deleter> const &
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
	shared_ptr<T, Deleter> const &,
	shared_ptr<U, Deleter> const &
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
	shared_ptr<T, Deleter> &,
	shared_ptr<T, Deleter> &
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
	std::basic_ostream<Ch, Traits> &,
	shared_ptr<T, Deleter> const &
);

#ifdef FCPPT_TR1_DETAIL_USE_BOOST_TR1
template<
	typename T,
	template<
		typename
	> class Deleter
>
T *
get_pointer(
	fcppt::shared_ptr<
		T,
		Deleter
	>
);
#endif

}

#endif
