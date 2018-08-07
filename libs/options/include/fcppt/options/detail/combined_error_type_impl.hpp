//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_DETAIL_COMBINED_ERROR_TYPE_IMPL_HPP_INCLUDED
#define FCPPT_OPTIONS_DETAIL_COMBINED_ERROR_TYPE_IMPL_HPP_INCLUDED

#include <fcppt/options/missing_error_fwd.hpp>
#include <fcppt/options/other_error_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace options
{
namespace detail
{

template<
	typename T1,
	typename T2
>
struct combined_error_type_impl
{
	template<
		typename T
	>
	using
	assert_type
	=
	std::integral_constant<
		bool,
		std::is_same<
			T,
			fcppt::options::missing_error
		>::value
		||
		std::is_same<
			T,
			fcppt::options::other_error
		>::value
	>;

	static_assert(
		assert_type<
			T1
		>::value,
		""
	);

	static_assert(
		assert_type<
			T2
		>::value,
		""
	);

	typedef
	std::conditional_t<
		std::is_same<
			T1,
			fcppt::options::other_error
		>::value
		||
		std::is_same<
			T2,
			fcppt::options::other_error
		>::value,
		fcppt::options::other_error,
		fcppt::options::missing_error
	>
	type;
};

}
}
}

#endif
