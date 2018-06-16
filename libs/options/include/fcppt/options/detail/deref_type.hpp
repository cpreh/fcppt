//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_DETAIL_DEREF_TYPE_HPP_INCLUDED
#define FCPPT_OPTIONS_DETAIL_DEREF_TYPE_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>
#include <fcppt/unique_ptr_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace options
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
	fcppt::unique_ptr<
		Parser
	>
>
{
	typedef
	Parser
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

{
	typedef
	Parser
	type;
};

}
}
}

#endif
