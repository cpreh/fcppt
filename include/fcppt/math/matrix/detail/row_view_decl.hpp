//          Copyright Carl Philipp Reh 2009 - 2012.
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
	typename N
>
class row_view
{
public:
	typedef T value_type;

	typedef typename N::value_type size_type;

	typedef T &reference;

	typedef T const &const_reference;

	typedef T *pointer;

	typedef T const *const_pointer;

	typedef pointer iterator;

	typedef const_pointer const_iterator;

	row_view(
		pointer,
		size_type index,
		size_type stride,
		size_type size
	);

	iterator
	begin() const;

	pointer
	data() const;

	size_type
	size() const;
private:
	pointer rep_;

	size_type size_;
};

}
}
}
}

#endif
