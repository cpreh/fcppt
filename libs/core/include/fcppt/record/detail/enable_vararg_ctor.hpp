//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_DETAIL_ENABLE_VARARG_CTOR_HPP_INCLUDED
#define FCPPT_RECORD_DETAIL_ENABLE_VARARG_CTOR_HPP_INCLUDED

#include <fcppt/record/detail/enable_vararg_ctor_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace record
{
namespace detail
{

template<
	typename Ref,
	typename... Args
>
using
enable_vararg_ctor
=
std::enable_if_t<
	fcppt::record::detail::enable_vararg_ctor_impl<
		Ref,
		Args...
	>::value
>;

}
}
}

#endif
