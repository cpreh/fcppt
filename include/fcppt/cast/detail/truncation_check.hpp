//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CAST_DETAIL_TRUNCATION_CHECK_HPP_INCLUDED
#define FCPPT_CAST_DETAIL_TRUNCATION_CHECK_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/cast/to_signed.hpp>
#include <fcppt/cast/to_unsigned.hpp>
#include <fcppt/config/external_begin.hpp>
#include <limits>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace cast
{
namespace detail
{

template<
	typename Dest,
	typename Source
>
typename
std::enable_if<
	std::is_signed<
		Dest
	>::value
	==
	std::is_signed<
		Source
	>::value
	&&
	sizeof(
		Dest
	)
	>=
	sizeof(
		Source
	),
	fcppt::optional<
		Dest
	>
>::type
truncation_check(
	Source const _source
)
{
	return
		fcppt::optional<
			Dest
		>(
			_source
		);
}

template<
	typename Dest,
	typename Source
>
typename
std::enable_if<
	std::is_unsigned<
		Dest
	>::value
	&&
	std::is_unsigned<
		Source
	>::value
	&&
	sizeof(
		Dest
	)
	<
	sizeof(
		Source
	),
	fcppt::optional<
		Dest
	>
>::type
truncation_check(
	Source const _source
)
{
	typedef
	fcppt::optional<
		Dest
	>
	dest_type;

	return
		fcppt::cast::size<
			Source
		>(
			std::numeric_limits<
				Dest
			>::max()
		)
		<
		_source
		?
			dest_type()
		:
			dest_type(
				fcppt::cast::size<
					Dest
				>(
					_source
				)
			)
		;
}

template<
	typename Dest,
	typename Source
>
typename
std::enable_if<
	std::is_signed<
		Dest
	>::value
	&&
	std::is_signed<
		Source
	>::value
	&&
	sizeof(
		Dest
	)
	<
	sizeof(
		Source
	),
	fcppt::optional<
		Dest
	>
>::type
truncation_check(
	Source const _source
)
{
	typedef fcppt::optional<
		Dest
	> dest_type;

	return
		fcppt::cast::size<
			Source
		>(
			std::numeric_limits<
				Dest
			>::max()
		)
		<
		_source
		||
		fcppt::cast::size<
			Source
		>(
			std::numeric_limits<
				Dest
			>::min()
		)
		>
		_source
		?
			dest_type()
		:
			dest_type(
				fcppt::cast::size<
					Dest
				>(
					_source
				)
			)
		;
}

template<
	typename Dest,
	typename Source
>
typename
std::enable_if<
	std::is_unsigned<
		Dest
	>::value
	&&
	std::is_signed<
		Source
	>::value,
	fcppt::optional<
		Dest
	>
>::type
truncation_check(
	Source const _source
)
{
	typedef fcppt::optional<
		Dest
	> dest_type;

	return
		_source
		<
		fcppt::literal<
			Source
		>(
			0
		)
		?
			dest_type()
		:
			fcppt::cast::detail::truncation_check<
				Dest
			>(
				fcppt::cast::to_unsigned(
					_source
				)
			);
}

template<
	typename Dest,
	typename Source
>
typename
std::enable_if<
	std::is_signed<
		Dest
	>::value
	&&
	std::is_unsigned<
		Source
	>::value,
	fcppt::optional<
		Dest
	>
>::type
truncation_check(
	Source const _source
)
{
	typedef fcppt::optional<
		Dest
	> dest_type;

	typedef typename std::make_unsigned<
		Dest
	>::type intermediate_type;

	typedef fcppt::optional<
		intermediate_type
	> intermediate_dest;

	intermediate_dest const dest(
		fcppt::cast::detail::truncation_check<
			intermediate_type
		>(
			_source
		)
	);

	return
		!dest
		||
		fcppt::cast::to_unsigned(
			std::numeric_limits<
				Dest
			>::max()
		)
		<
		*dest
		?
			dest_type()
		:
			dest_type(
				fcppt::cast::size<
					Dest
				>(
					fcppt::cast::to_signed(
						_source
					)
				)
			);
}

}
}
}

#endif
