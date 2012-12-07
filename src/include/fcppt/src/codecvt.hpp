//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SRC_CODECVT_HPP_INCLUDED
#define FCPPT_SRC_CODECVT_HPP_INCLUDED

#include <fcppt/exception.hpp>
#include <fcppt/text.hpp>
#include <fcppt/assert/unreachable.hpp>
#include <fcppt/container/data_end.hpp>
#include <fcppt/container/raw_vector_impl.hpp>
#include <fcppt/src/codecvt_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstring>
#include <iterator>
#include <locale>
#include <string>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

template<
	typename Out,
	typename In,
	typename Function
>
std::basic_string<Out> const
codecvt(
	std::basic_string<In> const &_string,
	std::locale const &_locale,
	Function const &_function
)
{
	typedef std::basic_string<
		Out
	> return_type;

	typedef fcppt::container::raw_vector<
		Out
	> buffer_type;

	if(
		_string.empty()
	)
		return return_type();

	fcppt::codecvt_type const &conv(
		std::use_facet<
			fcppt::codecvt_type
		>(
			_locale
		)
	);

	buffer_type buf(
		_string.size()
	);

	typedef fcppt::codecvt_type::state_type state_type;

	state_type state;

	std::memset(
		&state,
		0,
		sizeof(state_type)
	);

	Out *to = buf.data();

	for(
		In const *from = _string.data(),
		*from_next = nullptr;
		; // loop forever
		from = from_next
	)
	{
		Out *to_next;

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
				to,
				buf.data_end(),
				to_next
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
			throw fcppt::exception(
				FCPPT_TEXT("codecvt: error!")
			);
		case std::codecvt_base::partial:
			{
				typename buffer_type::difference_type const diff(
					std::distance(
						buf.data(),
						to_next
					)
				);

				buf.resize(
					buf.size() * 2
				);

				to = buf.data() + diff;
			}
			continue;
		case std::codecvt_base::ok:
			return
				return_type(
					buf.data(),
					to_next
				);
		}

		FCPPT_ASSERT_UNREACHABLE;
	}
}

}

#endif
