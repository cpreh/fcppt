//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_STRONG_TYPEDEF_DECL_HPP_INCLUDED
#define FCPPT_STRONG_TYPEDEF_DECL_HPP_INCLUDED

#include <fcppt/nonassignable.hpp>
#include <fcppt/strong_typedef_fwd.hpp>

namespace fcppt
{

/// Used to create strong typedefs.
/* The first template parameter is the type to be wrapped.
 * The second template parameter should be a unique tag type.
 * strong_typedef has an explicit construct and
 * explicit get member functions.
 * Almost all operators are overloaded and found in their
 * respective header.
 * Currently \em not overloaded are:
 * - The logical operators, that include bool operator!, operator && and operator ||
 * - The member and pointer operators: operator[], operator*, operator&, operator-> and operator->*
 * - operator(), operator, (sequence),  operator new, operator new[], operator delete and operator delete[]
*/
template<
	typename T,
	typename Tag
>
class strong_typedef
{
public:
	typedef T value_type;

	typedef Tag tag_type;

	strong_typedef();

	template<
		typename U
	>
	explicit strong_typedef(
		U const &
	);

	template<
		typename U
	>
	strong_typedef &
	operator=(
		U const &
	);

	T &
	get();

	T const &
	get() const;

	void
	swap(
		strong_typedef &
	);
private:
	T value_;
};

template<
	typename T,
	typename Tag
>
class strong_typedef<
	T &,
	Tag
>
{
	FCPPT_NONASSIGNABLE(
		strong_typedef
	);
public:
	typedef T value_type;

	typedef T &reference;

	typedef Tag tag_type;

	explicit strong_typedef(
		reference
	);

	reference
	get() const;
private:
	reference ref_;
};


template<
	typename T,
	typename Tag
>
void
swap(
	strong_typedef<T, Tag> &,
	strong_typedef<T, Tag> &
);

}

#endif
