//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_DETAIL_FIND_ELEMENT_PREDICATE_HPP_INCLUDED
#define FCPPT_RECORD_DETAIL_FIND_ELEMENT_PREDICATE_HPP_INCLUDED

#include <fcppt/record/element_to_label.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/functions/lambda/apply.hpp>
#include <brigand/functions/lambda/bind.hpp>
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
	typename Label
>
using
find_element_predicate
=
std::is_same<
	::brigand::bind<
		fcppt::record::element_to_label,
		::brigand::_1
	>,
	::brigand::pin<
		Label
	>
>;

}
}
}

#endif
