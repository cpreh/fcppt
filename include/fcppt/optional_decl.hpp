//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_DECL_HPP_INCLUDED
#define FCPPT_OPTIONAL_DECL_HPP_INCLUDED

#include <fcppt/optional_fwd.hpp>
#include <fcppt/safe_bool.hpp>
#include <fcppt/alignment/array.hpp>
#include <fcppt/detail/enable_optional_ref_conv.hpp>
#include <fcppt/detail/enable_optional_value_conv.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/type_traits/alignment_of.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

template<
	typename T
>
class optional
{
	FCPPT_SAFE_BOOL(
		optional
	)
public:
	typedef T value_type;

	typedef T &reference;

	typedef T const &const_reference;

	typedef T *pointer;

	typedef T const *const_pointer;

	optional();

	explicit
	optional(
		const_reference
	);

	template<
		typename Other
	>
	explicit
	optional(
		optional<
			Other
		> const &,
		typename detail::enable_optional_value_conv<
			T,
			Other,
			void
		>::type const * = 0
	);

	optional(
		optional const &
	);

	optional &
	operator=(
		optional const &
	);

	optional &
	operator=(
		const_reference
	);

	template<
		typename Other
	>
	typename detail::enable_optional_value_conv<
		T,
		Other,
		optional &
	>::type
	operator=(
		optional<
			Other
		> const &
	);

	~optional();

	reference
	operator*();

	const_reference
	operator*() const;

	pointer
	operator->();

	const_pointer
	operator->() const;

	void
	reset();

	bool
	has_value() const;
private:
	bool
	boolean_test() const;

	pointer
	construct(
		const_reference
	);

	template<
		typename Other
	>
	pointer
	construct(
		optional<
			Other
		> const &
	);

	optional &
	assign(
		const_reference
	);

	template<
		typename Other
	>
	optional &
	assign(
		optional<
			Other
		> const &
	);

	template<
		typename Other
	>
	void
	copy_from_other(
		Other const &
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
class optional<
	T &
>
{
	FCPPT_SAFE_BOOL(
		optional
	)
public:
	typedef T &reference;

	typedef T *pointer;

	optional();

	explicit
	optional(
		reference
	);

	template<
		typename Other
	>
	explicit optional(
		optional<
			Other &
		>,
		typename detail::enable_optional_ref_conv<
			T,
			Other
		>::type * = 0
	);

	optional(
		optional const &
	);

	optional &
	operator=(
		optional const &
	);

	~optional();

	reference
	operator*() const;

	pointer
	operator->() const;

	bool
	has_value() const;
private:
	bool
	boolean_test() const;

	pointer data_;
};

}

#endif
