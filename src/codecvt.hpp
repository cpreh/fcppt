//          Copyright Carl Philipp Reh 2009 - 2010.
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
		codecvt_t const &cvt,
		state_type &state,
		wchar_t const *const from,
		wchar_t const *const from_end,
		wchar_t const *&from_next,
		char *const to,
		char *const to_limit,
		char *&to_next
	)
	{
		return cvt.out(
			state,
			from,
			from_end,
			from_next,
			to,
			to_limit,
			to_next
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
		codecvt_t const &cvt,
		state_type &state,
		char const *const from,
	        char const *const from_end,
	        char const *&from_next,
	        wchar_t *const to,
	        wchar_t *const to_limit,
	        wchar_t *&to_next)
	{
		return cvt.in(
			state,
			from,
			from_end,
			from_next,
			to,
			to_limit,
			to_next);
	}
};

std::locale const
get_locale()
{
	static std::locale loc("");
	return loc;
}

template<
	typename Out,
	typename In
>
std::basic_string<Out> const
codecvt(
	std::basic_string<In> const &s
)
{
	typedef std::basic_string<
		Out
	> return_type;

	typedef fcppt::container::raw_vector<
		Out
	> buffer_type;

	if(s.empty())
		return return_type();

	std::locale const &loc(
		get_locale()
	);

	codecvt_t const &conv(
		std::use_facet<codecvt_t>(
			loc
		)
	);

	buffer_type buf(
		s.size()
	);

	state_type state;

	Out *to = buf.data();

	for(
		In const *from = s.data(), *from_next = 0;
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
				fcppt::container::data_end(s),
				from_next,
				to,
				buf.data_end(),
				to_next
			)
		);

		switch(result)
		{
		case std::codecvt_base::noconv:
			return return_type(
				s.begin(),
				s.end()
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
			return return_type(
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
