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


#ifndef FCPPT_MATH_DIM_BASIC_DECL_HPP_INCLUDED
#define FCPPT_MATH_DIM_BASIC_DECL_HPP_INCLUDED

#include <fcppt/math/dim/basic_fwd.hpp>
#include <fcppt/math/dim/max_ctor_params.hpp>
#include <fcppt/math/detail/make_op_decl.hpp>
#include <fcppt/math/detail/make_variadic_constructor_decl.hpp>
#include <fcppt/math/detail/array_adapter.hpp>
#include <fcppt/type_traits/is_iterator.hpp>
#include <boost/utility/enable_if.hpp>

namespace fcppt
{
namespace math
{
namespace dim
{
namespace detail
{

template<
	typename T,
	typename N,
	typename S
>
class typedef_helper {
public:
	typedef math::detail::array_adapter<
		basic<
			T,
			N,
			S
		>,
		T,
		typename N::value_type
	> type;
};

}


template<
	typename T,
	typename N,
	typename S
>
class basic
: public detail::typedef_helper<T, N, S>::type {
	typedef typename detail::typedef_helper<T, N, S>::type base;
public:
	typedef N dim_wrapper;
	typedef S storage_type;

	typedef typename base::size_type size_type;
	typedef typename base::value_type value_type;
	typedef typename base::reference reference;
	typedef typename base::const_reference const_reference;
	typedef typename base::pointer pointer;
	typedef typename base::const_pointer const_pointer;
	typedef typename base::iterator iterator;
	typedef typename base::const_iterator const_iterator;
	typedef typename base::reverse_iterator reverse_iterator;
	typedef typename base::const_reverse_iterator const_reverse_iterator;

	basic();

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
		>::type end);

#define FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR_MAX_SIZE FCPPT_MATH_DIM_MAX_CTOR_PARAMS
	FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR_DECL(basic)
#undef FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR_MAX_SIZE
public:

#define FCPPT_MATH_DIM_BASIC_DECLARE_OPERATOR(op)\
FCPPT_MATH_DETAIL_MAKE_OP_DECL(basic, op)
	FCPPT_MATH_DIM_BASIC_DECLARE_OPERATOR(+=)
	FCPPT_MATH_DIM_BASIC_DECLARE_OPERATOR(-=)
	FCPPT_MATH_DIM_BASIC_DECLARE_OPERATOR(*=)
	FCPPT_MATH_DIM_BASIC_DECLARE_OPERATOR(/=)
	FCPPT_MATH_DIM_BASIC_DECLARE_OPERATOR(%=)
#undef FCPPT_MATH_DIM_BASIC_DECLARE_OPERATOR

	basic &
	operator*=(
		value_type const &);

	basic &
	operator/=(
		value_type const &);

	reference
	operator[](
		size_type);

	const_reference
	operator[](
		size_type) const;

	pointer data();
	const_pointer data() const;

	size_type size() const;

	reference w();
	const_reference w() const;
	reference h();
	const_reference h() const;
	reference d();
	const_reference d() const;

	size_type content() const;

	static basic const
	null();

	void resize(
		size_type);
private:
	S storage;
};

}
}
}

#endif

