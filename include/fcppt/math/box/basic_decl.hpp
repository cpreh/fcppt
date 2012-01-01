//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_BASIC_DECL_HPP_INCLUDED
#define FCPPT_MATH_BOX_BASIC_DECL_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/box/basic_fwd.hpp>
#include <fcppt/math/dim/basic_decl.hpp>
#include <fcppt/math/dim/static.hpp>
#include <fcppt/math/vector/basic_decl.hpp>
#include <fcppt/math/vector/static.hpp>


namespace fcppt
{
namespace math
{
namespace box
{

/// The basic box class
/**
 * @param T The value type to hold
 * @param N The static size of the box
*/
template<
	typename T,
	math::size_type N
>
class basic
{
public:
	typedef T value_type;

	typedef value_type scalar;

	typedef math::size_type size_type;

	typedef typename math::vector::static_<
		T,
		N
	>::type vector;

	typedef typename math::dim::static_<
		T,
		N
	>::type dim;

	basic();

	basic(
		vector const &,
		dim const &
	);

	static basic const
	null();

	value_type
	content() const;

	value_type
	w() const;

	value_type
	h() const;

	value_type
	d() const;

	vector const
	pos() const;

	vector const
	max() const;

	dim const
	size() const;

	value_type
	pos(
		size_type
	) const;

	value_type
	max(
		size_type
	) const;

	value_type
	size(
		size_type
	) const;

	value_type
	left() const;

	value_type
	top() const;

	value_type
	front() const;

	value_type
	right() const;

	value_type
	bottom() const;

	value_type
	back() const;

	void
	w(
		value_type
	);

	void
	h(
		value_type
	);

	void
	d(
		value_type
	);

	void
	pos(
		vector const &
	);

	void
	size(
		dim const &
	);

	void
	pos(
		size_type index,
		value_type
	);

	void
	size(
		size_type index,
		value_type
	);

	void
	left(
		value_type
	);

	void
	top(
		value_type
	);

	void
	front(
		value_type
	);

	void
	swap(
		basic &
	);
private:
	vector pos_;

	dim size_;
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
operator !=(
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
