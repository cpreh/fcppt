//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_SPHERE_BASIC_DECL_HPP_INCLUDED
#define FCPPT_MATH_SPHERE_BASIC_DECL_HPP_INCLUDED

#include <fcppt/math/sphere/basic_fwd.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/math/vector/basic_decl.hpp>
#include <fcppt/math/size_type.hpp>

namespace fcppt
{
namespace math
{
namespace sphere
{

/// The basic sphere class
/**
 * @param T The value type to hold
 * @param N The static size of the sphere
*/
template<
	typename T,
	size_type N
>
class basic
{
public:
	typedef T value_type;
	typedef T &reference;
	typedef T const &const_reference;

	typedef typename vector::static_<
		value_type,
		N
	>::type point_type;

	/// Constructs a sphere from @a origin and @a radius
	basic(
		point_type const &origin,
		const_reference radius
	);

	point_type &
	origin();

	point_type const &
	origin() const;

	reference
	radius();

	const_reference
	radius() const;

	void
	swap(
		basic &
	);
private:
	point_type origin_;
	value_type radius_;
};

template<
	typename T,
	size_type N
>
bool
operator==(
	basic<T, N> const &,
	basic<T, N> const &
);

template<
	typename T,
	size_type N
>
bool
operator!=(
	basic<T, N> const &,
	basic<T, N> const &
);

template<
	typename T,
	size_type N
>
void
swap(
	basic<T, N> &,
	basic<T, N> &
);

}
}
}

#endif
