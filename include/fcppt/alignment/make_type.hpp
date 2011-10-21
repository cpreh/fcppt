//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALIGNMENT_MAKE_TYPE_HPP_INCLUDED
#define FCPPT_ALIGNMENT_MAKE_TYPE_HPP_INCLUDED

#include <fcppt/alignment/size_type.hpp>
#include <fcppt/alignment/detail/make_type.hpp>


namespace fcppt
{
namespace alignment
{

/// Creates a nested typedef 'type' of type @tparam T with alignment @tparam Alignment
/**
 * Which alignments are supported is unspecified.
 * In most cases you can only use alignments that are a power 2.
 * Also, every compiler implements a limit depending on the platform.
*/
template<
	typename T,
	size_type Alignment
>
struct make_type
:
fcppt::alignment::detail::make_type<
	T,
	Alignment
>
{};

}
}

#endif
