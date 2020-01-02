//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_STATIC_STORAGE_DECL_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_STATIC_STORAGE_DECL_HPP_INCLUDED

#include <fcppt/cast/size_fun.hpp>
#include <fcppt/container/array/size.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/static_storage_fwd.hpp>
#include <fcppt/type_traits/integral_cast.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename T,
	fcppt::math::size_type N
>
class static_storage
{
public:
	typedef
	std::array<
		T,
		N
	>
	array_type;

	typedef
	fcppt::type_traits::integral_cast<
		fcppt::math::size_type,
		fcppt::cast::size_fun,
		fcppt::container::array::size<
			array_type
		>
	>
	storage_size;

	typedef
	typename
	array_type::value_type
	value_type;

	typedef
	typename
	array_type::reference
	reference;

	typedef
	typename
	array_type::const_reference
	const_reference;

	typedef
	typename
	array_type::pointer
	pointer;

	typedef
	typename
	array_type::const_pointer
	const_pointer;

	template<
		typename... Args
	>
	explicit
	static_storage(
		Args &&...
	);

	explicit
	static_storage(
		array_type &&
	);

	explicit
	static_storage(
		array_type const &
	);

	reference
	operator[](
		fcppt::math::size_type
	);

	const_reference
	operator[](
		fcppt::math::size_type
	) const;

	pointer
	data();

	const_pointer
	data() const;
private:
	array_type impl_;
};

}
}
}

#endif
