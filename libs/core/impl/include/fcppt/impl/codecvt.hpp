//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_IMPL_CODECVT_HPP_INCLUDED
#define FCPPT_IMPL_CODECVT_HPP_INCLUDED

#include <fcppt/exception.hpp>
#include <fcppt/text.hpp>
#include <fcppt/assert/unreachable.hpp>
#include <fcppt/cast/to_unsigned.hpp>
#include <fcppt/container/data_end.hpp>
#include <fcppt/container/buffer/object.hpp>
#include <fcppt/container/buffer/resize_write_area.hpp>
#include <fcppt/impl/codecvt_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iterator>
#include <locale>
#include <string>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace impl
{

template<
	typename Out,
	typename In,
	typename Function
>
std::basic_string<
	Out
>
codecvt(
	std::basic_string<
		In
	> const &_string,
	std::locale const &_locale,
	Function const &_function
)
{
	typedef
	std::basic_string<
		Out
	>
	return_type;

	typedef
	fcppt::container::buffer::object<
		Out
	>
	buffer_type;

	if(
		_string.empty()
	)
		return
			return_type();

	fcppt::impl::codecvt_type const &conv(
		std::use_facet<
			fcppt::impl::codecvt_type
		>(
			_locale
		)
	);

	buffer_type buf{
		_string.size()
	};

	typedef
	fcppt::impl::codecvt_type::state_type
	state_type;

	state_type state{};

	for(
		In const *from = _string.data(),
		*from_next = nullptr;
		; // loop forever
		from = from_next
	)
	{
		Out *to_next{
			nullptr
		};

		std::codecvt_base::result const result(
			(
				conv.*_function
			)(
				state,
				from,
				fcppt::container::data_end(
					_string
				),
				from_next,
				buf.write_data(),
				buf.write_data_end(),
				to_next
			)
		);

		if(
			to_next
			!=
			nullptr
		)
			buf.written(
				fcppt::cast::to_unsigned(
					std::distance(
						buf.write_data(),
						to_next
					)
				)
			);

		switch(
			result
		)
		{
		case std::codecvt_base::noconv:
			return
				return_type(
					_string.begin(),
					_string.end()
				);
		case std::codecvt_base::error:
			throw
				fcppt::exception{
					FCPPT_TEXT("codecvt: error!")
				};
		case std::codecvt_base::partial:
			buf =
				fcppt::container::buffer::resize_write_area(
					buf,
					buf.read_size()
					*
					2u
				);
			continue;
		case std::codecvt_base::ok:
			return
				return_type(
					buf.begin(),
					buf.end()
				);
		}

		FCPPT_ASSERT_UNREACHABLE;
	}
}

}
}

#endif
