/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2009 Carl Philipp Reh (sefi@s-e-f-i.de)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/


#ifndef FCPPT_MATH_VECTOR_BASIC_DECL_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_BASIC_DECL_HPP_INCLUDED

#include <fcppt/math/vector/basic_fwd.hpp>
#include <fcppt/math/vector/max_ctor_params.hpp>
#include <fcppt/math/detail/make_op_decl.hpp>
#include <fcppt/math/detail/make_variadic_constructor_decl.hpp>
#include <fcppt/math/detail/array_adapter.hpp>
#include <fcppt/type_traits/is_iterator.hpp>
#include <boost/utility/enable_if.hpp>

namespace fcppt
{
namespace math
{
namespace vector
{

template<
	typename T,
	typename N,
	typename S
>
class basic
{
public:
	typedef N dim_wrapper;

	typedef S storage_type;

	typedef typename N::value_type size_type;
	typedef T value_type;
	typedef value_type &reference;
	typedef value_type const &const_reference;
	typedef T *pointer;
	typedef T const *const_pointer;
	typedef pointer iterator;
	typedef const_pointer const_iterator;
	typedef std::reverse_iterator<iterator> reverse_iterator;
	typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

	basic();

	explicit basic(
		storage_type const &
	);

	template<
		typename In
	>
	basic(
		In beg,
		typename boost::enable_if<
			type_traits::is_iterator<
				In
			>,
			In
		>::type end
	);

	FCPPT_MATH_DETAIL_ARRAY_ADAPTER(basic)

#define FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR_MAX_SIZE FCPPT_MATH_VECTOR_MAX_CTOR_PARAMS
	FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR_DECL(basic)
#undef FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR_MAX_SIZE
public:

#define FCPPT_MATH_VECTOR_BASIC_DECLARE_OPERATOR(op)\
FCPPT_MATH_DETAIL_MAKE_OP_DECL(basic, op)
	FCPPT_MATH_VECTOR_BASIC_DECLARE_OPERATOR(+=)
	FCPPT_MATH_VECTOR_BASIC_DECLARE_OPERATOR(-=)
	FCPPT_MATH_VECTOR_BASIC_DECLARE_OPERATOR(*=)
	FCPPT_MATH_VECTOR_BASIC_DECLARE_OPERATOR(/=)
	FCPPT_MATH_VECTOR_BASIC_DECLARE_OPERATOR(%=)
#undef FCPPT_MATH_VECTOR_BASIC_DECLARE_OPERATOR

	basic &
	operator*=(
		value_type const &
	);

	basic &
	operator/=(
		value_type const &
	);

	const_reference
	operator[](
		size_type
	) const;

	reference
	operator[](
		size_type
	);

	pointer
	data();

	const_pointer
	data() const;

	size_type
	size() const;

	static basic const
	null();

	reference x();
	const_reference x() const;
	reference y();
	const_reference y() const;
	reference z();
	const_reference z() const;
	reference w();
	const_reference w() const;

	void
	resize(
		size_type
	);
private:
	S storage;
};

}
}
}

#endif
