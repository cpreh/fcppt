//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SCOPED_PTR_DECL_HPP_INCLUDED
#define FCPPT_SCOPED_PTR_DECL_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <fcppt/null_ptr.hpp>
#include <fcppt/safe_bool.hpp>
#include <fcppt/scoped_ptr_fwd.hpp>
#include <fcppt/unique_ptr_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/type_traits/add_reference.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

template<
	typename Type,
	typename Deleter
>
class scoped_ptr
{
	FCPPT_NONCOPYABLE(
		scoped_ptr
	);

	FCPPT_SAFE_BOOL(
		scoped_ptr
	)
public:
	typedef typename boost::add_reference<
		Type
	>::type reference;

	typedef Type *pointer;

	explicit
	scoped_ptr(
		pointer = fcppt::null_ptr()
	);

	template<
		typename Other
	>
	explicit
	scoped_ptr(
		fcppt::unique_ptr<
			Other,
			Deleter
		>
	);

	~scoped_ptr();

	void
	reset(
		pointer = fcppt::null_ptr()
	);

	reference
	operator*() const;

	pointer
	operator->() const;

	pointer
	get() const;

	bool
	operator! () const;

	void
	swap(
		scoped_ptr &
	);

	template<
		typename Other
	>
	void
	take(
		fcppt::unique_ptr<
			Other,
			Deleter
		>
	);

	fcppt::unique_ptr<
		Type,
		Deleter
	>
	release();
private:
	bool
	boolean_test() const;

	pointer ptr_;
};

template<
	typename Type,
	typename Deleter
>
void
swap(
	fcppt::scoped_ptr<
		Type,
		Deleter
	> &,
	fcppt::scoped_ptr<
		Type,
		Deleter
	> &
);

}

#endif
