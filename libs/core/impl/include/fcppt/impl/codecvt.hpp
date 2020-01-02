//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_IMPL_CODECVT_HPP_INCLUDED
#define FCPPT_IMPL_CODECVT_HPP_INCLUDED

#include <fcppt/assert/unreachable.hpp>
#include <fcppt/cast/to_unsigned.hpp>
#include <fcppt/container/data_end.hpp>
#include <fcppt/container/buffer/object.hpp>
#include <fcppt/impl/codecvt_type.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iterator>
#include <locale>
#include <string>
#include <string_view>
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
fcppt::optional::object<
	std::basic_string<
		Out
	>
>
codecvt(
	std::basic_string_view<
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
	fcppt::optional::object<
		return_type
	>
	optional_return_type;

	typedef
	fcppt::container::buffer::object<
		Out
	>
	buffer_type;

	if(
		_string.empty()
	)
		return
			optional_return_type(
				return_type{}
			);

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

		typename
		buffer_type::size_type const written{
			to_next
			!=
			nullptr
			?
				fcppt::cast::to_unsigned(
					std::distance(
						buf.write_data(),
						to_next
					)
				)
			:
				0u
		};

		buf.written(
			written
		);

		switch(
			result
		)
		{
		case std::codecvt_base::noconv:
			return
				optional_return_type{
					return_type(
						_string.begin(),
						_string.end()
					)
				};
		case std::codecvt_base::error:
			return
				optional_return_type{};
		case std::codecvt_base::partial:
			if(
				written
				==
				0u
			)
				return
					optional_return_type{
						return_type(
							buf.begin(),
							buf.end()
						)
					};

			buf.resize_write_area(
				buf.read_size()
				*
				2u
			);
			continue;
		case std::codecvt_base::ok:
			return
				optional_return_type{
					return_type(
						buf.begin(),
						buf.end()
					)
				};
		}

		FCPPT_ASSERT_UNREACHABLE;
	}
}

}
}

#endif
