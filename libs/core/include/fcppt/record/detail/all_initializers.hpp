//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_DETAIL_ALL_INITIALIZERS_HPP_INCLUDED
#define FCPPT_RECORD_DETAIL_ALL_INITIALIZERS_HPP_INCLUDED

#include <fcppt/brigand/all_of.hpp>
#include <fcppt/record/detail/contains_initializer.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/functions/lambda/apply.hpp>
#include <brigand/functions/lambda/bind.hpp>
#include <brigand/types/args.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace record
{
namespace detail
{

template<
	typename Elements,
	typename Args
>
using
all_initializers
=
fcppt::brigand::all_of<
	Elements,
	::brigand::bind<
		fcppt::record::detail::contains_initializer,
		::brigand::pin<
			Args
		>,
		::brigand::_1
	>
>;

}
}
}

#endif
