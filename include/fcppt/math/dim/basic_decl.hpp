//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DIM_BASIC_DECL_HPP_INCLUDED
#define FCPPT_MATH_DIM_BASIC_DECL_HPP_INCLUDED

#include <fcppt/math/dim/basic_fwd.hpp>
#include <fcppt/math/dim/max_ctor_params.hpp>
#include <fcppt/math/detail/make_op_decl.hpp>
#include <fcppt/math/detail/make_variadic_constructor_decl.hpp>
#include <fcppt/math/detail/array_adapter.hpp>
#include <fcppt/type_traits/is_iterator.hpp>
#include <boost/utility/enable_if.hpp>
#include <iterator>

namespace fcppt
{
namespace math
{
namespace dim
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

	basic(
		basic const &
	);

	template<
		typename OtherStorage
	>
	basic(
		basic<
			T,
			N,
			OtherStorage
		> const &
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

	FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR_DECL(
		FCPPT_MATH_DIM_MAX_CTOR_PARAMS,
		basic
	)

	basic &
	operator=(
		basic const &
	);

	template<
		typename OtherStorage
	>
	basic &
	operator=(
		basic<
			T,
			N,
			OtherStorage
		> const &
	);

	~basic();

// \cond
#define FCPPT_MATH_DIM_BASIC_DECLARE_OPERATOR(op)\
FCPPT_MATH_DETAIL_MAKE_OP_DECL(\
	template<\
		typename OtherStorage\
	>, \
	(basic<T, N, OtherStorage>),\
	3,\
	op \
)
// \endcond

	FCPPT_MATH_DIM_BASIC_DECLARE_OPERATOR(+=)
	FCPPT_MATH_DIM_BASIC_DECLARE_OPERATOR(-=)
	FCPPT_MATH_DIM_BASIC_DECLARE_OPERATOR(*=)
	FCPPT_MATH_DIM_BASIC_DECLARE_OPERATOR(/=)
	FCPPT_MATH_DIM_BASIC_DECLARE_OPERATOR(%=)
#undef FCPPT_MATH_DIM_BASIC_DECLARE_OPERATOR

	basic &
	operator*=(
		value_type const &
	);

	basic &
	operator/=(
		value_type const &
	);

	reference
	operator[](
		size_type
	);

	const_reference
	operator[](
		size_type
	) const;

	pointer
	data();

	const_pointer
	data() const;

	size_type
	size() const;

	reference w();
	const_reference w() const;
	reference h();
	const_reference h() const;
	reference d();
	const_reference d() const;

	size_type
	content() const;

	static basic const
	null();

	void
	resize(
		size_type
	);

	void
	swap(
		basic &
	);
private:
	S storage;
};

template<
	typename T,
	typename N,
	typename S
>
void
swap(
	basic<T, N, S> &,
	basic<T, N, S> &
);

}
}
}

#endif

