//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_OPTIONAL_BASE_DECL_HPP_INCLUDED
#define FCPPT_DETAIL_OPTIONAL_BASE_DECL_HPP_INCLUDED

#include <fcppt/alignment/array.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/type_traits/alignment_of.hpp>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace detail
{

template<
	typename T
>
class optional_base
{
protected:
	typedef T &reference;

	typedef T const &const_reference;

	typedef T *pointer;

	typedef T const *const_pointer;

	optional_base();

	optional_base(
		const_reference
	);

	optional_base(
		optional_base const &
	);

	optional_base &
	operator=(
		optional_base const &
	);

	optional_base &
	operator=(
		const_reference
	);

	~optional_base();

	pointer
	data() const;

	void
	do_reset();
private:
	pointer
	construct(
		const_reference
	);

	pointer
	construct(
		optional_base const &
	);

	void
	destroy();

	typedef typename alignment::array<
		unsigned char,
		sizeof(T),
		boost::alignment_of<
			T
		>::value
	>::type storage_type;

	storage_type storage_;

	pointer data_;
};

template<
	typename T
>
class optional_base<
	T &
>
{
protected:
	typedef T &reference;

	typedef T &const_reference;

	typedef T *pointer;

	typedef T *const_pointer;

	optional_base();

	optional_base(
		const_reference
	);

	template<
		typename Other
	>
	explicit optional_base(
		Other *
	);

	optional_base(
		optional_base const &
	);

	optional_base &
	operator=(
		optional_base const &
	);

	template<
		typename Other
	>
	optional_base &
	operator=(
		Other *
	);

	optional_base &
	operator=(
		const_reference
	);

	~optional_base();

	pointer
	data() const;

	void
	do_reset();
private:
	pointer data_;
};

}
}

#endif
