//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_WEAK_PTR_DECL_HPP_INCLUDED
#define FCPPT_WEAK_PTR_DECL_HPP_INCLUDED

#include <fcppt/shared_ptr_fwd.hpp>
#include <fcppt/weak_ptr_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/weak_ptr.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

template<
	typename Type,
	typename Deleter
>
class weak_ptr
{
public:
	typedef boost::weak_ptr<
		Type
	> impl_type;

	typedef fcppt::shared_ptr<
		Type,
		Deleter
	> shared_ptr;

	typedef Type element_type;

	weak_ptr();

	template<
		typename Other
	>
	weak_ptr(
		fcppt::weak_ptr<
			Other,
			Deleter
		> const &
	);

	template<
		typename Other
	>
	weak_ptr(
		fcppt::shared_ptr<
			Other,
			Deleter
		> const &
	);

	shared_ptr const
	lock() const;

	long
	use_count() const;

	bool
	expired() const;

	void
	reset();

	void
	swap(
		weak_ptr &
	);

	impl_type const
	boost_ptr() const;
private:
	impl_type impl_;
};

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
	> const &,
	fcppt::weak_ptr<
		Type2,
		Deleter
	> const &
);

template<
	typename Type,
	typename Deleter
>
void
swap(
	fcppt::weak_ptr<
		Type,
		Deleter
	> &,
	fcppt::weak_ptr<
		Type,
		Deleter
	> &
);

}

#endif
