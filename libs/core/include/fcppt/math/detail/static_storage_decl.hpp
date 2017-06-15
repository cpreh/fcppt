//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_STATIC_STORAGE_DECL_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_STATIC_STORAGE_DECL_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/static_storage_fwd.hpp>
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
:
	public
		std::array<
			T,
			N
		>
{
public:
	typedef
	std::array<
		T,
		N
	>
	array_type;

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

	array_type const &
	get() const;
};

}
}
}

#endif
