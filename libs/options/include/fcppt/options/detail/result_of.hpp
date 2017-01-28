
//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_DETAIL_RESULT_OF_HPP_INCLUDED
#define FCPPT_OPTIONS_DETAIL_RESULT_OF_HPP_INCLUDED

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
struct result_of
{
	typedef
	typename
	Parser::result_type
	type;
};

template<
	typename Result
>
struct result_of<
	fcppt::options::base_unique_ptr<
		Result
	>
>
{
	typedef
	Result
	type;
};

}
}
}

#endif
