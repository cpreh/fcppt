//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_DETAIL_DEREF_TYPE_HPP_INCLUDED
#define FCPPT_PARSE_DETAIL_DEREF_TYPE_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>
#include <fcppt/parse/base_fwd.hpp>
#include <fcppt/parse/base_unique_ptr_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace parse
{
namespace detail
{

template<
	typename Parser
>
struct deref_type
{
	typedef
	std::remove_const_t<
		Parser
	>
	type;
};

template<
	typename Parser
>
struct deref_type<
	fcppt::reference<
		Parser const
	>
>
:
fcppt::parse::detail::deref_type<
	Parser
>
{
};

template<
	typename Result,
	typename Ch,
	typename Skipper
>
struct deref_type<
	fcppt::parse::base_unique_ptr<
		Result,
		Ch,
		Skipper
	>
>
{
	typedef
	fcppt::parse::base<
		Result,
		Ch,
		Skipper
	>
	type;
};

}
}
}

#endif
