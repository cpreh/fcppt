//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_DETAIL_DEREF_HPP_INCLUDED
#define FCPPT_OPTIONS_DETAIL_DEREF_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>
#include <fcppt/options/base_fwd.hpp>
#include <fcppt/options/base_unique_ptr_fwd.hpp>


namespace fcppt
{
namespace options
{
namespace detail
{

template<
	typename Parser
>
inline
Parser const &
deref(
	Parser const &_parser
)
{
	return
		_parser;
}

template<
	typename Result
>
inline
fcppt::options::base<
	Result
> const &
deref(
	fcppt::options::base_unique_ptr<
		Result
	> const &_ptr
)
{
	return
		*_ptr;
}

template<
	typename Parser
>
inline
Parser const &
deref(
	fcppt::reference<
		Parser const
	> const &_ref
)
{
	return
		fcppt::options::detail::deref(
			_ref.get()
		);
}

}
}
}

#endif
