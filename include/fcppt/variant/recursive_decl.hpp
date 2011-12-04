//          Copyright Carl Philipp Reh 2009 - 2011.
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

/**
\brief A wrapper for a recursive variant

\ingroup fcpptvariant

This class wraps a type \a T so that it can be forward declared. It is then
possible that \a T can recursively contain the yet to be defined variant. See
\ref variant_recursive This class is basically an internal class
which you don't have to use directly except when declaring which types a
variant can hold. \a T is added to the possible types of the variant
instead of <code>recursive<T></code>.
\see fcppt::variant::holds_type

\tparam T The type to wrap which doesn't need to be complete
*/
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
