//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_DETAIL_ROW_VIEW_DECL_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_DETAIL_ROW_VIEW_DECL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/container/to_reference_type.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/static_size.hpp>
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
	fcppt::math::size_type C,
	typename S
>
class row_view
{
public:
	typedef
	T
	value_type;

	typedef
	fcppt::math::size_type
	size_type;

	typedef
	fcppt::math::static_size<
		C
	>
	storage_size;

	typedef
	fcppt::container::to_reference_type<
		S
	>
	reference;

	typedef
	reference
	const_reference;

	row_view(
		S &,
		size_type index,
		size_type columns
	);

	const_reference
	operator[](
		size_type
	) const;
private:
	fcppt::reference<
		S
	> impl_;

	size_type offset_;
};

}
}
}
}

#endif
