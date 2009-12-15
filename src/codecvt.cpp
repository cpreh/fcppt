/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2009 Carl Philipp Reh (sefi@s-e-f-i.de)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/


#include <fcppt/codecvt.hpp>
#include <fcppt/container/data.hpp>
#include <fcppt/container/raw_vector_impl.hpp>
#include <fcppt/exception.hpp>
#include <fcppt/text.hpp>
#include <locale>
#include <iterator>

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
class call_traits;

template<>
class call_traits<char> {
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
		char *&to_next)
	{
		return cvt.out(
			state,
			from,
			from_end,
			from_next,
			to,
			to_limit,
			to_next);
	}
};

template<>
class call_traits<wchar_t> {
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
	static std::locale loc;
	return loc;
}

template<
	typename Out,
	typename In
>
std::basic_string<Out> const
convert(
	std::basic_string<In> const &s)
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
		s.size(),
		0
	);

	state_type state;

	Out *to = buf.data();
	for(
		In const *from = s.data(), *from_next = 0;
		from != from_next;
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

		switch(result) {
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
			break;
		case std::codecvt_base::ok:
			return return_type(
				buf.data(),
				to_next
			);
		default:
			throw fcppt::exception(
				FCPPT_TEXT("Unknown return value in codecvt!")
			);
		}
	}

	throw fcppt::exception(
		FCPPT_TEXT("codecvt: ok return value unreached!")
	);
}

}

std::string const
fcppt::narrow(
	std::wstring const &s)
{
	return convert<char>(s);
}

std::wstring const
fcppt::widen(
	std::string const &s)
{
	return convert<wchar_t>(s);
}
