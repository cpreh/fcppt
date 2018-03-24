//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_BRIGAND_DETAIL_PRINT_HPP_INCLUDED
#define FCPPT_BRIGAND_DETAIL_PRINT_HPP_INCLUDED

#include <fcppt/tag_type.hpp>
#include <fcppt/text.hpp>
#include <fcppt/use.hpp>
#include <fcppt/brigand/detail/print_one.hpp>
#include <fcppt/io/ostream.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/algorithms/for_each.hpp>
#include <brigand/sequences/back.hpp>
#include <brigand/sequences/list.hpp>
#include <brigand/types/type.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace brigand
{
namespace detail
{

template<
	typename Sequence
>
std::enable_if_t<
	std::is_same<
		Sequence,
		::brigand::list<>
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
	!std::is_same<
		Sequence,
		::brigand::list<>
	>::value,
	void
>
print(
	fcppt::io::ostream &_stream
)
{
	::brigand::for_each<
		::brigand::pop_back<
			Sequence
		>
	>(
		[
			&_stream
		](
			auto const _type
		)
		{
			FCPPT_USE(
				_type
			);

			fcppt::brigand::detail::print_one<
				::brigand::type_from<
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

	fcppt::brigand::detail::print_one<
		::brigand::back<
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
