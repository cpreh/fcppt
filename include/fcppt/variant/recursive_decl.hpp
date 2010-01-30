//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_RECURSIVE_DECL_HPP_INCLUDED
#define FCPPT_VARIANT_RECURSIVE_DECL_HPP_INCLUDED

#include <fcppt/variant/recursive_fwd.hpp>

namespace fcppt
{
namespace variant
{

template<
	typename T
>
class recursive
{
public:
	typedef T type;

	recursive(
		T const &
	);

	recursive(
		recursive const &
	);

	recursive &
	operator =(
		T const &
	);

	recursive &
	operator =(
		recursive const &
	);

	~recursive();

	void
	swap(
		recursive &
	);

	T &
	get() const;
private:
	static T * 
	copy(
		T const &
	);

	T *rep_;
};

template<
	typename T
>
void
swap(
	recursive<T> &,
	recursive<T> &
);

}
}

#endif
