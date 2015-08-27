//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_DETAIL_ROW_VIEW_DECL_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_DETAIL_ROW_VIEW_DECL_HPP_INCLUDED

#include <fcppt/math/matrix/detail/row_view_fwd.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{
namespace detail
{

template<
	typename T,
	typename C
>
class row_view
{
public:
	typedef
	T
	value_type;

	typedef
	typename
	C::value_type
	size_type;

	typedef T &reference;

	typedef T const &const_reference;

	typedef T *pointer;

	typedef T *iterator;

	typedef T const *const_iterator;

	row_view(
		pointer,
		size_type index,
		size_type columns
	);

	iterator
	begin() const;

	iterator
	end() const;

	constexpr
	size_type
	size() const;
private:
	pointer rep_;
};

}
}
}
}

#endif
