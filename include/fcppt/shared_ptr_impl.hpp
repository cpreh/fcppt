//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SHARED_PTR_IMPL_HPP_INCLUDED
#define FCPPT_SHARED_PTR_IMPL_HPP_INCLUDED

#include <fcppt/heap_deleter.hpp>
#include <fcppt/shared_ptr_decl.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/detail/make_shared_wrapper.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>


template<
	typename Type,
	typename Deleter
>
fcppt::shared_ptr<
	Type,
	Deleter
>::shared_ptr()
:
	impl_()
{
}

template<
	typename Type,
	typename Deleter
>
template<
	typename Other
>
fcppt::shared_ptr<
	Type,
	Deleter
>::shared_ptr(
	Other *const _ptr
)
:
	impl_(
		_ptr,
		Deleter()
	)
{
}

template<
	typename Type,
	typename Deleter
>
template<
	typename Other,
	typename Alloc
>
fcppt::shared_ptr<
	Type,
	Deleter
>::shared_ptr(
	Other *const _ptr,
	Alloc const &_alloc
)
:
	impl_(
		_ptr,
		Deleter(),
		_alloc
	)
{
}

template<
	typename Type,
	typename Deleter
>
template<
	typename Other
>
fcppt::shared_ptr<
	Type,
	Deleter
>::shared_ptr(
	fcppt::weak_ptr<
		Other,
		Deleter
	> const &_other
)
:
	impl_(
		_other
	)
{
}

template<
	typename Type,
	typename Deleter
>
template<
	typename Other
>
fcppt::shared_ptr<
	Type,
	Deleter
>::shared_ptr(
	fcppt::shared_ptr<
		Other,
		Deleter
	> const &_other
)
:
	impl_(
		_other.boost_ptr()
	)
{
}

template<
	typename Type,
	typename Deleter
>
template<
	typename Other
>
fcppt::shared_ptr<
	Type,
	Deleter
>::shared_ptr(
	fcppt::shared_ptr<
		Other,
		Deleter
	> const & _other,
	boost::detail::static_cast_tag
)
:
	impl_(
		_other.boost_ptr(),
		boost::detail::static_cast_tag()
	)
{
}

template<
	typename Type,
	typename Deleter
>
template<
	typename Other
>
fcppt::shared_ptr<
	Type,
	Deleter
>::shared_ptr(
	fcppt::shared_ptr<
		Other,
		Deleter
	> const &_other,
	boost::detail::const_cast_tag
)
:
	impl_(
		_other.boost_ptr(),
		boost::detail::const_cast_tag()
	)
{
}

template<
	typename Type,
	typename Deleter
>
template<
	typename Other
>
fcppt::shared_ptr<
	Type,
	Deleter
>::shared_ptr(
	fcppt::shared_ptr<
		Other,
		Deleter
	> const &_other,
	boost::detail::dynamic_cast_tag
)
:
	impl_(
		_other.boost_ptr(),
		boost::detail::dynamic_cast_tag()
	)
{
}

template<
	typename Type,
	typename Deleter
>
template<
	typename Other
>
fcppt::shared_ptr<
	Type,
	Deleter
>::shared_ptr(
	fcppt::shared_ptr<
		Other,
		Deleter
	> const &_other,
	boost::detail::polymorphic_cast_tag
)
:
	impl_(
		_other.boost_ptr(),
		boost::detail::polymorphic_cast_tag()
	)
{
}

template<
	typename Type,
	typename Deleter
>
template<
	typename Other
>
fcppt::shared_ptr<
	Type,
	Deleter
>::shared_ptr(
	fcppt::unique_ptr<
		Other,
		Deleter
	> _other
)
:
	impl_()
{
	impl_.reset(
		_other.release()
	);
}

template<
	typename Type,
	typename Deleter
>
template<
	typename Other
>
fcppt::shared_ptr<
	Type,
	Deleter
> &
fcppt::shared_ptr<
	Type,
	Deleter
>::operator=(
	fcppt::shared_ptr<
		Other,
		Deleter
	> const &_other
)
{
	impl_ = _other.impl;

	return *this;
}

template<
	typename Type,
	typename Deleter
>
template<
	typename Other
>
fcppt::shared_ptr<
	Type,
	Deleter
> &
fcppt::shared_ptr<
	Type,
	Deleter
>::operator=(
	fcppt::unique_ptr<
		Other,
		Deleter
	> _other
)
{
	impl_.reset(
		_other.release()
	);

	return *this;
}

template<
	typename Type,
	typename Deleter
>
fcppt::shared_ptr<
	Type,
	Deleter
>::~shared_ptr()
{
}

template<
	typename Type,
	typename Deleter
>
void
fcppt::shared_ptr<
	Type,
	Deleter
>::reset()
{
	impl_.reset();
}

template<
	typename Type,
	typename Deleter
>
template<
	typename Other
>
void
fcppt::shared_ptr<
	Type,
	Deleter
>::reset(
	Other *const _ptr
)
{
       	impl_.reset(
		_ptr,
		Deleter()
	);
}

template<
	typename Type,
	typename Deleter
>
template<
	typename Other,
	typename Alloc
>
void
fcppt::shared_ptr<
	Type,
	Deleter
>::reset(
	Other *const _ptr,
	Alloc const &_alloc
)
{
	impl_.reset(
		_ptr,
		Deleter(),
		_alloc
	);
}

template<
	typename Type,
	typename Deleter
>
typename fcppt::shared_ptr<
	Type,
	Deleter
>::reference
fcppt::shared_ptr<
	Type,
	Deleter
>::operator* () const
{
	return *impl_;
}

template<
	typename Type,
	typename Deleter
>
typename fcppt::shared_ptr<
	Type,
	Deleter
>::pointer
fcppt::shared_ptr<
	Type,
	Deleter
>::operator-> () const
{
	return impl_.operator->();
}

template<
	typename Type,
	typename Deleter
>
typename fcppt::shared_ptr<
	Type,
	Deleter
>::pointer
fcppt::shared_ptr<
	Type,
	Deleter
>::get() const
{
	return impl_.get();
}

// Doxygen says: warning: member `operator typename fcppt::shared_ptr' of class `shared_ptr' cannot be found
/// \cond FCPPT_DOXYGEN_DEBUG
template<
	typename Type,
	typename Deleter
>
fcppt::shared_ptr<
	Type,
	Deleter
>::operator
typename fcppt::shared_ptr<
	Type,
	Deleter
>::unspecified_bool_type() const
{
	return impl_;
}
/// \endcond

template<
	typename Type,
	typename Deleter
>
bool
fcppt::shared_ptr<
	Type,
	Deleter
>::operator! () const
{
	return !impl_;
}

template<
	typename Type,
	typename Deleter
>
bool
fcppt::shared_ptr<
	Type,
	Deleter
>::unique() const
{
	return impl_.unique();
}

template<
	typename Type,
	typename Deleter
>
long
fcppt::shared_ptr<
	Type,
	Deleter
>::use_count() const
{
	return impl_.use_count();
}

template<
	typename Type,
	typename Deleter
>
void
fcppt::shared_ptr<
	Type,
	Deleter
>::swap(
	fcppt::shared_ptr<
		Type,
		Deleter
	> &_other
)
{
	std::swap(
		impl_,
		_other.impl_
	);
 }

template<
	typename Type,
	typename Deleter
>
typename fcppt::shared_ptr<
	Type,
	Deleter
>::impl_type const
fcppt::shared_ptr<
	Type,
	Deleter
>::boost_ptr() const
{
	return impl_;
}

template<
	typename Type,
	typename Deleter
>
template<
	typename Other
>
fcppt::shared_ptr<
	Type,
	Deleter
>::shared_ptr(
	fcppt::detail::make_shared_wrapper<
		Other
	> const _other
)
:
	impl_(
		_other.get()
	)
{
	BOOST_STATIC_ASSERT((
		boost::is_same<
			Deleter,
			fcppt::heap_deleter
		>::value
	));
}

template<
	typename Type,
	typename Deleter
>
template<
	typename Other
>
fcppt::shared_ptr<
	Type,
	Deleter
>::shared_ptr(
	boost::shared_ptr<
		Other
	> const _other
)
:
	impl_(
		_other
	)
{
}

template<
	typename Type1,
	typename Type2,
	typename Deleter
>
bool
fcppt::operator==(
	fcppt::shared_ptr<
		Type1,
		Deleter
	> const &_a,
	fcppt::shared_ptr<
		Type2,
		Deleter
	> const &_b
)
{
	return
		_a.boost_ptr() == _b.boost_ptr();
}

template<
	typename Type1,
	typename Type2,
	typename Deleter
>
bool
fcppt::operator!=(
	fcppt::shared_ptr<
		Type1,
		Deleter
	> const &_a,
	fcppt::shared_ptr<
		Type2,
		Deleter
	> const &_b
)
{
	return
		!(_a == _b);
}

template<
	typename Type1,
	typename Type2,
	typename Deleter
>
bool
fcppt::operator<(
	fcppt::shared_ptr<
		Type1,
		Deleter
	> const &_a,
	fcppt::shared_ptr<
		Type2,
		Deleter
	> const &_b
)
{
	return
		_a.boost_ptr() < _b.boost_ptr();
}

template<
	typename Type,
	typename Deleter
>
void
fcppt::swap(
	fcppt::shared_ptr<
		Type,
		Deleter
	> &_a,
	fcppt::shared_ptr<
		Type,
		Deleter
	> &_b)
{
	_a.swap(
		_b
	);
}

template<
	typename Ch,
	typename Traits,
	typename Type,
	typename Deleter
>
std::basic_ostream<
	Ch,
	Traits
> &
fcppt::operator<< (
	std::basic_ostream<
		Ch,
		Traits
	> &_os,
	fcppt::shared_ptr<
		Type,
		Deleter
	> const &_ptr
)
{
	return
		_os << _ptr.get();
}

#endif
