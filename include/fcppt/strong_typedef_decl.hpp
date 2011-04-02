//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_STRONG_TYPEDEF_DECL_HPP_INCLUDED
#define FCPPT_STRONG_TYPEDEF_DECL_HPP_INCLUDED

#include <fcppt/strong_typedef_fwd.hpp>

namespace fcppt
{

/// Used to create strong typedefs.
/* The first template parameter is the type to be wrapped.
 * The second template parameter should be a unique tag type.
 * strong_typedef behaves like the wrapped type excpect that
 * its constructor is explicit.
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

	strong_typedef &
	operator++();

	strong_typedef &
	operator--();
private:
	T value_;
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
