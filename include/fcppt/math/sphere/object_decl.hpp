//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_SPHERE_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_MATH_SPHERE_OBJECT_DECL_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/sphere/object_fwd.hpp>
#include <fcppt/math/vector/object_decl.hpp>
#include <fcppt/math/vector/static.hpp>


namespace fcppt
{
namespace math
{
namespace sphere
{

/**
\brief The object sphere class

\tparam T The value type to hold
\tparam N The static size of the sphere
*/
template<
	typename T,
	fcppt::math::size_type N
>
class object
{
public:
	typedef T value_type;

	typedef T &reference;

	typedef T const &const_reference;

	typedef
	fcppt::math::vector::static_<
		value_type,
		N
	> point_type;

	/// Constructs a sphere from @a origin and @a radius
	object(
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
		object &
	);
private:
	point_type origin_;

	value_type radius_;
};

template<
	typename T,
	fcppt::math::size_type N
>
bool
operator==(
	fcppt::math::sphere::object<T, N> const &,
	fcppt::math::sphere::object<T, N> const &
);

template<
	typename T,
	fcppt::math::size_type N
>
bool
operator!=(
	fcppt::math::sphere::object<T, N> const &,
	fcppt::math::sphere::object<T, N> const &
);

template<
	typename T,
	fcppt::math::size_type N
>
void
swap(
	fcppt::math::sphere::object<T, N> &,
	fcppt::math::sphere::object<T, N> &
);

}
}
}

#endif
