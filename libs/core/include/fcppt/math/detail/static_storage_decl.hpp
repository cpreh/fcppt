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
	using
	array_type
	=
	std::array<
		T,
		N
	>;

	using
	storage_size
	=
	fcppt::type_traits::integral_cast<
		fcppt::math::size_type,
		fcppt::cast::size_fun,
		fcppt::container::array::size<
			array_type
		>
	>;

	using
	value_type
	=
	typename
	array_type::value_type;

	using
	reference
	=
	typename
	array_type::reference;

	using
	const_reference
	=
	typename
	array_type::const_reference;

	using
	pointer
	=
	typename
	array_type::pointer;

	using
	const_pointer
	=
	typename
	array_type::const_pointer;

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

	[[nodiscard]]
	reference
	operator[](
		fcppt::math::size_type
	);

	[[nodiscard]]
	const_reference
	operator[](
		fcppt::math::size_type
	) const;

	[[nodiscard]]
	pointer
	data();

	[[nodiscard]]
	const_pointer
	data() const;
private:
	array_type impl_;
};

}
}
}

#endif
