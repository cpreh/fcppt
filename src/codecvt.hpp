//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CODECVT_HPP_INCLUDED
#define FCPPT_CODECVT_HPP_INCLUDED

#include <fcppt/container/data.hpp>
#include <fcppt/container/data_end.hpp>
#include <fcppt/container/raw_vector_impl.hpp>
#include <fcppt/exception.hpp>
#include <fcppt/text.hpp>
#include <locale>
#include <iterator>
#include <string>

namespace fcppt
{

namespace
{

typedef std::mbstate_t state_type;

typedef std::codecvt<
	wchar_t,
	char,
	state_type
> codecvt_t;

template<
	typename OutCh
>
struct call_traits;

template<>
struct call_traits<
	char
>
{
public:
	static std::codecvt_base::result
	conv(
		codecvt_t const &_cvt,
		state_type &_state,
		wchar_t const *const _from,
		wchar_t const *const _from_end,
		wchar_t const *&_from_next,
		char *const _to,
		char *const _to_limit,
		char *&_to_next
	)
	{
		return
			_cvt.out(
				_state,
				_from,
				_from_end,
				_from_next,
				_to,
				_to_limit,
				_to_next
			);
	}
};

template<>
struct call_traits<
	wchar_t
>
{
public:
	static std::codecvt_base::result
	conv(
		codecvt_t const &_cvt,
		state_type &_state,
		char const *const _from,
	        char const *const _from_end,
	        char const *&_from_next,
	        wchar_t *const _to,
	        wchar_t *const _to_limit,
	        wchar_t *&_to_next
	)
	{
		return
			_cvt.in(
				_state,
				_from,
				_from_end,
				_from_next,
				_to,
				_to_limit,
				_to_next
			);
	}
};

template<
	typename Out,
	typename In
>
std::basic_string<Out> const
codecvt(
	std::basic_string<In> const &_string,
	std::locale const &_locale
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

	codecvt_t const &conv(
		std::use_facet<codecvt_t>(
			_locale
		)
	);

	buffer_type buf(
		_string.size()
	);

	state_type state;

	Out *to = buf.data();

	for(
		In const *from = _string.data(), *from_next = 0;
		; // loop forever
		from = from_next
	)
	{
		Out *to_next;

		std::codecvt_base::result const result(
			call_traits<Out>::conv(
				conv,
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

				buf.resize(buf.size() * 2);

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

		throw fcppt::exception(
			FCPPT_TEXT("Unknown return value in codecvt!")
		);
	}
}

}

}

#endif
