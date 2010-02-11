//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_DECL_HPP_INCLUDED
#define FCPPT_OPTIONAL_DECL_HPP_INCLUDED

#include <fcppt/optional_fwd.hpp>
#include <fcppt/safe_bool.hpp>
#include <fcppt/alignment/array.hpp>
#include <boost/type_traits/alignment_of.hpp>

namespace fcppt
{

template<
	typename T
>
class optional
{
	FCPPT_SAFE_BOOL(optional)
public:
	typedef T value_type;
	typedef T &reference;
	typedef T const &const_reference;
	typedef T *pointer;
	typedef T const *const_pointer;

	optional();

	// intentionally not explicit
	optional(
		const_reference
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
private:
	bool
	boolean_test() const;

	pointer
	construct(
		const_reference
	);

	pointer
	construct(
		optional const &
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

}

#endif
