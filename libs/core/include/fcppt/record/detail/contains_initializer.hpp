//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_DETAIL_CONTAINS_INITIALIZER_HPP_INCLUDED
#define FCPPT_RECORD_DETAIL_CONTAINS_INITIALIZER_HPP_INCLUDED

#include <fcppt/record/element_to_label.hpp>
#include <fcppt/record/detail/label_is_same.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/algorithms/find.hpp>
#include <brigand/functions/lambda/apply.hpp>
#include <brigand/functions/lambda/bind.hpp>
#include <brigand/functions/logical/not.hpp>
#include <brigand/sequences/list.hpp>
#include <brigand/types/args.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace record
{
namespace detail
{

template<
	typename Args,
	typename Element
>
using
contains_initializer
=
::brigand::not_<
	std::is_same<
		::brigand::find<
			Args,
			::brigand::bind<
				fcppt::record::detail::label_is_same,
				::brigand::pin<
					fcppt::record::element_to_label<
						Element
					>
				>,
				::brigand::_1
			>
		>,
		::brigand::list<>
	>
>;

}
}
}

#endif
