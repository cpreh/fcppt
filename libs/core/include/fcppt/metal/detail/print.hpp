//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_METAL_DETAIL_PRINT_HPP_INCLUDED
#define FCPPT_METAL_DETAIL_PRINT_HPP_INCLUDED

#include <fcppt/tag_type.hpp>
#include <fcppt/text.hpp>
#include <fcppt/use.hpp>
#include <fcppt/algorithm/loop.hpp>
#include <fcppt/algorithm/loop_break_metal.hpp>
#include <fcppt/io/ostream.hpp>
#include <fcppt/metal/detail/print_one.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace metal
{
namespace detail
{

template<
	typename Sequence
>
std::enable_if_t<
	::metal::empty<
		Sequence
	>::value,
	void
>
print(
	fcppt::io::ostream &
)
{
}

template<
	typename Sequence
>
std::enable_if_t<
	!::metal::empty<
		Sequence
	>::value,
	void
>
print(
	fcppt::io::ostream &_stream
)
{
	fcppt::algorithm::loop(
		::metal::range<
			Sequence,
			::metal::number<
				0
			>,
			::metal::dec<
				::metal::size<
					Sequence
				>
			>
		>{},
		[
			&_stream
		](
			auto const _type
		)
		{
			FCPPT_USE(
				_type
			);

			fcppt::metal::detail::print_one<
				fcppt::tag_type<
					decltype(
						_type
					)
				>
			>(
				_stream
			);

			_stream
				<< FCPPT_TEXT(',');
		}
	);

	fcppt::metal::detail::print_one<
		::metal::back<
			Sequence
		>
	>(
		_stream
	);
}

}
}
}

#endif
